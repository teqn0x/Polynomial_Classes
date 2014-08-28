import os,sys

from polynomial import polynomial

def main():

    print 'Creating Polynomial p1 with list [1,2,3]'
    p1 = polynomial([1,2,3])
    'Representation of p1 gives:'
    print p1
    
    print 'Creating polynomial p2 with list [100,200]'
    p2 = polynomial([100,200])
    
    print 'p1.add(p2) gives'
    print p1.add(p2)
    print 'p1+p2 gives'
    print p1+p2

    print 'p1(1) gives'
    print p1(1)
    
    print 'p1(-1) gives'
    print p1(-1)

    print '(p1+p2)(10) gives'
    print (p1+p2)(10)

    print 'p1.mul(p1) gives'
    print p1.mul(p1)
    print 'p1 * p1 gives'
    print p1*p1
    print 'p1*p2 + p1 gives'
    print p1 * p2 + p1
    
    print 'p1.roots gives'
    print p1.roots()
    print 'p2 roots gives'
    print p2.roots()

    print 'make polynomial 3 with list [3,2,-1]'
    p3 = polynomial([3,2,-1])
    print 'p3.roots is'
    print p3.roots()

    print 'p1*p2 roots gives:'
    print (p1*p2).roots()


if __name__ == "__main__":
    main()
