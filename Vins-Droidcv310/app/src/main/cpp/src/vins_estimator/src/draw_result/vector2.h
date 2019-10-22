#ifndef H_VECTOR2
#define H_VECTOR2

#include <iostream>
#include <cmath>

template <typename T>
class MyVector2
{
	public:
		//
		// Constructors
		//

    MyVector2()
		{
			x = 0;
			y = 0;
		}

    MyVector2(T _x, T _y)
		{
			x = _x;
			y = _y;
		}

    MyVector2(const MyVector2 &v)
		{
			x = v.x;
			y = v.y;
		}

		void set(const MyVector2 &v)
		{
			x = v.x;
			y = v.y;
		}

		//
		// Operations
		//	
		T dist2(const MyVector2 &v)
		{
			T dx = x - v.x;
			T dy = y - v.y;
			return dx * dx + dy * dy;	
		}

		float dist(const MyVector2 &v)
		{
			return sqrtf(dist2(v));
		}

		T x;
		T y;

};

template<typename T>
std::ostream &operator << (std::ostream &str, MyVector2<T> const &point)
{
	return str << "Point x: " << point.x << " y: " << point.y;
}

template<typename T>
bool operator == (MyVector2<T> v1, MyVector2<T> v2)
{
	return (v1.x == v2.x) && (v1.y == v2.y);
}
#endif
