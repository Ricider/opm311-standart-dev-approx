#include <stdio.h>
#include <math.h>

float absolute(float inp){
	if (inp<0) return -inp;
	return inp;
}

float mad(float* arr,int len){
	float mean=0;
	float deviation=0;
	
	float* endAddr=arr+len;
	while (arr!=endAddr) mean+=*(arr++); 
	mean/=len;
	
	arr-=len;
	while (arr!=endAddr) deviation+=absolute(*(arr++)-mean); 
	deviation/=len;
	
	return deviation;
}

float dumbSD(float* arr,int len){
	return 1.25f*mad(arr,len);
}

float standartDev(float* arr,int len){
	float mean=0;
	float deviation=0;
	
	float* endAddr=arr+len;
	while (arr!=endAddr) mean+=*(arr++); 
	mean/=len;
	
	arr-=len;
	while (arr!=endAddr) deviation+=(*(arr)-mean)*(*(arr++)-mean); 
	deviation/=len;
	deviation=sqrt(deviation);
	
	return deviation;
}

float main(){
	float arr[]={20,4,1,6,2,34,12};
	printf("result of mad times 1.25= %f\n",dumbSD(arr,7));
	printf("result of real sd= %f\n",standartDev(arr,7));
}
