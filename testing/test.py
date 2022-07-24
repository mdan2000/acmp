import argparse
import os
import sys
from importlib import import_module
sys.path.append(os.getcwd())
import stress_tests

def createParser():
    parser = argparse.ArgumentParser()
    parser.add_argument('-l', '--language', nargs=1, default='c++', help="""
        Language of your source.
        If it C++ - it will compile 'g++ source_name -o prog -std=c++17'
        If it pytohn it will executable with 'python3 source_name'
        Default main.cpp
        Can be c++ or python
        """)
    parser.add_argument('-s', '--source', nargs=1, default='main.cpp', help="""
        Source name of solution. Default main.cpp
        """)
    parser.add_argument('-T', '--tests', nargs=1, default='tests.py', help="""
        Name with file of python tests. It must be 2 functions
        get_tests()
        get_ans()
        On tests[i] will be ans ans[i]
        Default tests.py
        """)
    return parser

def make_test(test):
    test_filename = 'test.txt'
    with open(test_filename, 'w') as w:
        w.write(test)
    return test_filename

def compile_cpp(namespace):
    compile_res_filename = 'compile_res.txt'
    compile_command = f'g++ {namespace.source} -o prog -std=c++17 > {compile_res_filename}'
    os.system(compile_command)
    
    if os.path.getsize(compile_res_filename):
        with open(compile_res_filename, 'r') as r:
            error = r.read()
        print(f'Can\'t compile c++, error:\n {error}')
        return False
    return True


def run_cpp(namespace):
    is_compile = compile_cpp(namespace)
    
    if not is_compile:
        return

    tests = stress_tests.get_tests()
    ans = stress_tests.get_ans()

    if len(tests) != len(ans):
        print('Len of tests not equal len ans')
        return

    tests_res = ['' for i in range(len(tests))]
    tests_error = [False for i in range(len(tests))]

    for i in range(len(tests)):
        test_filename = make_test(tests[i])
        test_res_filename = f'{i}.out'
        run_test_command = f'./prog 0< {test_filename} 2> error.test 1> {test_res_filename}'
        os.system(run_test_command)
        if os.path.getsize('error.test') != 0:
            test_error_filename = f'{i + 1}.error'
            tests_res[i] = f'{i} test break with error in {test_error_filename}'
            tests_error[i] = True

            with open('error.test', 'r') as r:
                test_error = r.read()

            with open(test_error_filename, 'w') as w:
                w.write('Test:\n{test}\nfailed with error:\n{test_error}')
            continue

        with open(test_res_filename, 'r') as r:
            tests_res[i] = r.read()

    for i in range(len(tests)):
        if (tests_error[i]):
            print(tests_res[i])
        elif tests_res[i] != ans[i]:
            print(f'{i + 1} test failed\nTest:\n{tests[i]}\nAnswer:\n{ans[i]}\nResult:\n{tests_res[i]}')
        else:
            print(f'{i + 1} test PASSED')

print(os.getcwd())    

parser = createParser()
namespace = parser.parse_args()
if namespace.language == 'c++':
    run_cpp(namespace)
