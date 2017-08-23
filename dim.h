#ifndef DIM_H
#define DIM_H

struct dim1{
	dim1() = default;
	dim1(int a):width(a){};
	int width;
};

struct dim2:dim1{
	dim2() = default;
	dim2(int a,int b):dim1(a),length(b){};
	int length;
};

struct dim3:dim2{
	dim3() = default;
	dim3(int a,int b,int c):dim2(a,b),height(c){};
	
	int height;
};
inline dim1 operator+(const dim1& a,const dim1& b){
	return {a.width+a.width};
}

inline dim1 operator-(const dim1& a,const dim1& b){
	return {a.width-a.width};
}

inline dim2 operator+(const dim2& a,const dim2& b){
	return {a.width+a.width,a.length+b.length};
}

inline dim2 operator-(const dim2& a,const dim2& b){
	return {a.width-a.width,a.length-b.length};
}

inline dim3 operator+(const dim3& a,const dim3& b){
	return {a.width+a.width,a.length+b.length,a.height+b.height};
}

inline dim3 operator-(const dim3& a,const dim3& b){
	return {a.width-a.width,a.length-b.length,a.height-b.height};
}

#endif

