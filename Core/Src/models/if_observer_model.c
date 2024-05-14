/*
 * if_observer_model.c
 *
 *  Created on: May 8, 2024
 *      Author: iddou
 */


#include <models/if_observer_model.h>

void Observer_Init(void){

}

float Observer_Start(float Uinv,float Io,float Vo){
static float x[2]={0,0},p[2][2]={{1,0},{0,1}};
float b[2][2],k[2],y[2];
/* calculate X' */
y[0]=A11*x[0]+A12*x[1]+B11*Uinv+B12*Io;
y[1]=A21*x[0]+A22*x[1]+B21*Uinv+B22*Io;
/* calculate P' */

b[0][0]=(A11*p[0][0]+A12*p[1][0])*A11+(A11*p[0][1]+A12*p[1][1])*A12+1;
b[0][1]=(A11*p[0][0]+A12*p[1][0])*A21+(A11*p[0][1]+A12*p[1][1])*A22;
b[1][0]=(A21*p[0][0]+A22*p[1][0])*A11+(A21*p[0][1]+A22*p[1][1])*A12;
b[1][1]=(A21*p[0][0]+A22*p[1][0])*A21+(A21*p[0][1]+A22*p[1][1])*A22+1;

/* calculate K */
k[0]=b[0][1]/(b[1][1]+1);
k[1]=b[1][1]/(b[1][1]+1);
/* calculate X */

x[0]=y[0]+k[0]*(Vo-y[1]);
x[1]=y[1]+k[1]*(Vo-y[1]);

/* calculate P */
p[0][0]=b[0][0]-(k[0]*b[1][0]);
p[0][1]=+b[0][1]-(k[0]*b[1][1]);
p[1][0]=b[1][0]*(1-k[1]);
p[1][1]=b[1][1]*(1-k[1]);

return x[0];

}






/*
 * kalman_filter_model.c
 *
 *  Created on: May 11, 2024
 *      Author: anis
 */
#define A0 0.975f
#define A1 -0.025f
#define A2 2.1739f

#define A0A0 0.950625f
#define A0A1 -0.024375f
#define A1A1 -0.000625f
#define A0A2 2.1195525f
#define A1A2 -0.0543475f
#define A2A2 4.72584121f





#define B0 0.0250f
#define B3 -2.1739f





float calculate_kalman_current(float Uinv,float Io,float Vo){

static float ypre[2]={0,0},pmes[2][2]={{1,0},{0,1}};
float k[2],y[2],p[2][2];

p[0][0]= A0A0*pmes[0][0]+A0A1*pmes[1][0]+A0A1*pmes[0][1]+A1A1*pmes[1][1]+1;
p[0][1]= A0A2*pmes[0][0]+A1A2*pmes[1][0]+A0*pmes[0][1]+A1*pmes[1][1];
p[1][0]= A0A2*pmes[0][0]+A0*pmes[1][0]+A1A2*pmes[0][1]+A1*pmes[1][1];
p[1][1]= A2A2*pmes[0][0]+A2*pmes[1][0]+A2*pmes[0][1]+pmes[1][1]+1;

k[0]=p[0][1]/(p[1][1]+1);
k[1]=p[1][1]/(p[1][1]+1);    //k1 k3
y[0]=A0*ypre[0]+A1*ypre[1]+ B0*Uinv;
y[1]=A2*ypre[0]+ypre[1] + B3*Io; //xbar

//float x0est=y0+k1*(Vo-y1);
//float x1est=y1+k1*(Vo-y1);

pmes[0][0]=p[0][0]-p[1][0]*k[0];  //pk
pmes[0][1]=p[0][1]-p[1][1]*k[0];
pmes[1][0]=p[1][0]-p[1][0]*k[1];
pmes[1][1]=p[1][1]-p[1][1]*k[1];

//y0pre=x0est;
ypre[0]=y[0]+k[0]*(Vo-y[1]);  //xchapeau
//y1pre=x1est;
ypre[1]=y[1]+k[0]*(Vo-y[1]);

return ypre[0];
}



