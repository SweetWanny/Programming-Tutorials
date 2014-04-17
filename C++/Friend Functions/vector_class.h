#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H

// Here's our VECTOR class -- As you can see it's painfully simple 
class VECTOR
{
	public:
	
		// Our default constructor
		// Here we set everything to zero
		VECTOR():x(0.0f),y(0.0f),z(0.0f) { /* do nothing */ }

		// Overloaded constructor
		VECTOR(float x_val, float y_val, float z_val);

		// This is how you declare "friend functions" -- First thing to notice is that 
		// we are declaring it as public method, however, we can declare it WHERE EVER we 
		// want -- So if we moved this declaration under the "private:" label, it would work
		// the exact same -- Second thing to notice is the keyword "friend" -- This
		// must be used when declaring a "friend function".  The rest of the declaration
		// follows the normal rules:  return type, function name, parameter(s)
		friend float dotProduct(VECTOR vec1, VECTOR vec2);

	private:

		float x;
		float y;
		float z;

};

// EXTRA -- EXTRA -- READ ALL ABOUT IT

// More times than not, people are confused by the following syntax:
//
// VECTOR():x(0.0f),y(0.0f),z(0.0f) {}
//
// This is "special syntax" for setting the value of class members -- This 
// syntax CAN ONLY be used for constructors or copy constructors -- But it's really
// not tricky -- The above syntax for all intensive purposes is the same thing
// as this:
//
// VECTOR()
// {
//	  x = 0.0f;
//	  y = 0.0f;
//	  z = 0.0f;
// }
//
// Hopefully now the special syntax won't be so special %)

#endif