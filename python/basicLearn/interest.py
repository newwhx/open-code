#!/usr/bin/env python
# -*- coding: utf-8 -*-

def test_print(arg):
    #Four methods to print a var value
    print "Method 1: the var's value is %s" %arg
    print "Method 2: the var's value is " + str(arg)
    print "Method 3: the var's value is " + `arg`
    print "Method 4: the var's value is " + repr(arg)

if __name__ == "__main__":
    test_print(42)
    test_print(10000L)
    test_print('Hello world')
    test_print([1, 2, 3, 4,5])

