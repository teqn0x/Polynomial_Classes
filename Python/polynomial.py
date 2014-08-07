import os,sys,math,cmath

class polynomial:

	def __init__(self,lcoeffs):	
		self.lcoeffs = lcoeffs
		#Making it floats because of the division by 0 when doing the ABC formula
		for i in range(len(self.lcoeffs)):
			self.lcoeffs[i] = float(self.lcoeffs[i])
		
	def __str__(self):
		outstring = ''
		N = len(self.lcoeffs)
		for i in range(N):
			if i == N-1:
				outstring += '%s' % self.lcoeffs[i]
			elif i == N-2:
				outstring += '%s x + ' % self.lcoeffs[i]
			else:
				outstring += '%s x^%s + ' % (self.lcoeffs[i],N-i-1)
		return outstring
		
	def __repr__(self):
		return str(self)
		
	def __add__(self,other):
		if not isinstance(other,polynomial):
			sys.exit('Cannot add a polynomial and a non-polynomial object, exiting!')
		N1 = len(self.lcoeffs)
		N2 = len(other.lcoeffs)
		#Make copies so that the original lists do not get adjusted
		lcoeffs1 = list(self.lcoeffs)
		lcoeffs2 = list(other.lcoeffs)
		if N1 < N2:
			lcoeffs1 = [0]*(N2-N1) + lcoeffs1 
			lcoeffs3 = [0]*N2
			for i in range(N2):
				lcoeffs3[i] = lcoeffs1[i] + lcoeffs2[i]
		if N2 < N1:
			lcoeffs2 = [0]*(N1-N2) + lcoeffs2
			lcoeffs3 = [0]*N1
			for i in range(N1):
				lcoeffs3[i] = lcoeffs1[i] + lcoeffs2[i]
		return polynomial(lcoeffs3)
		
	def __mul__(self,other):
		if not isinstance(other,polynomial):
			sys.exit('Cannot multiply a polynomial and a non-polynomial object, exiting!')
		lcoeffs1 = list(self.lcoeffs)
		lcoeffs2 = list(other.lcoeffs)
		N1 = len(lcoeffs1)
		N2 = len(lcoeffs2)
		lcoeffs1.reverse()
		lcoeffs2.reverse()
		lcoeffs = [0]*(N1+N2-1)
		for i in range(len(lcoeffs1)):
			for j in range(len(lcoeffs2)):
				lcoeffs[i+j] += (lcoeffs1[i] * lcoeffs2[j])
		lcoeffs.reverse()
		return polynomial(lcoeffs)
		
	def __call__(self,x):
		y = float(0)
		coeffs = list(self.lcoeffs)
		coeffs.reverse()
		N = len(coeffs)
		for i in range(N):
			y+= coeffs[i] * (x ** (i))
		return y
			
	def add(self,other):
		return self + other
			
	def mul(self,other):
		return self * other
		
	def val(self,x):
		return self(x)
		
	def coeff(self,i):
		lcoeffs = list(self.coeffs)
		lcoeffs.reverse()
		return lcoeffs[i]
			
	def roots(self):
		if len(self.lcoeffs) == 1:
			print 'This is a constant, no polynomial'
			return []
		elif len(self.lcoeffs) == 2:
			return [-1 * self.lcoeffs[1] / self.lcoeffs[0]]
		elif len(self.lcoeffs) == 3:
			a = self.lcoeffs[0]
			b = self.lcoeffs[1]
			c = self.lcoeffs[2]
			D = b*b - 4*a*c
			
			xp1 = -1 * b / (2*a)
			if D < 0:
				xp2 = complex( 0 , math.sqrt(-1*D) / (2*a) )
			else:
				xp2 = math.sqrt(D) / (2*a)
				
			return [xp1+xp2,xp1-xp2]
		else:
			print 'Order is too high to solve for roots.'
			return []
			
	def valHorner(self,x):
		y = 0
		for n in self.lcoeffs:
			y = (y + n)*x
		return y
	
				
		
			

	
		
			