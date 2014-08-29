// General class that takes care of Complex Numbers
// More advanced functions like trigoniometrie etc. can be added later if required

import java.lang.Number;
import java.lang.Math;

public class Complex {

    private double re;
    private double im;

    Complex(){
	re = 0.0;
	im = 0.0;
    }
    
    Complex(double re){
	this.re = re;
    }

    Complex(double re, double im){
	this.re = re;
	this.im = im;
    }

    Complex(Complex z){
	re = z.real();
	im = z.imag();
    }

    //Constructor from polar coordinates:
    public static Complex fromPolar(double r, double theta){
	return new Complex(r*Math.cos(theta), r*Math.sin(theta));
    }

    public double real(){
	return re;
    }
    
    public double imag(){
	return im;
    }
    
    public Complex add(Complex z){
	return new Complex( re + z.real(), im + z.imag());
    }

    public Complex sub(Complex z){
	return new Complex( re - z.real(), im - z.imag());
    }
    
    public Complex mul(Complex z){
	// (a + ib) (c+id) = (ac - bd) + i (ad + cb)
	double a = re;
	double b = im;
	double c = z.real();
	double d = z.imag();
	return new Complex( a*c - b*d, a*d + c*b);
    }

    public Complex div(Complex z){
	// (a + ib) / (c + id) = (a + ib) (c-id) / (c^2+d^2) = ( (ac+bd) + i (bc - ad) ) / (c^2 + d^2)
	double a = re;
	double b = im;
	double c = z.real();
	double d = z.imag();
	
	return new Complex( (a*c + b*d) / (c*c + d*d), (b*c - a*d) / (c*c + d*d) );
    }

    public Complex conj(){
	return new Complex(re, -1*im);
    }

    public double mod(){
	return Math.sqrt(re*re + im*im);
    }

    public double arg(){
	double theta = Math.atan(im / re);
	
	if(re > 0){
	    return theta;
	}
	else if(re < 0 && im >= 0){
	    return theta + Math.PI;
	}
	else if(re < 0 && im < 0){
	    return theta - Math.PI;
	}
	else if(re == 0 && im > 0){
	    return Math.PI / 2.0;
	}
	else if(re == 0 && im < 0){
	    return -1 * Math.PI / 2.0;
	}
	else {
	    return 0.0; //Should actually throw some UnderfinedArgumentException or something, or use Double, which can be equal to null.
	}
    }
	 
    public Complex exp(){
	return new Complex(Math.exp(re) * Math.cos(im), Math.exp(re) * Math.sin(im));
    }
    

    // Format functions
    public String toString(){
	return Double.toString(re)+ " + " + Double.toString(im)+"i";
    }
    
    public static String toString(Complex z){
	return Double.toString(z.real()) + " + " + Double.toString(z.imag()) + "i";
    }
    
    public static String toString(double re, double im){
	return Double.toString(re) + " + " + Double.toString(im) + "i";
    }

}
