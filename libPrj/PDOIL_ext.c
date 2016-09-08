//#include <math.h>

double sin(double);

#include <GL/gl.h>
#include <gl/glext.h>
//#include <gl/glut.h>
#include "SOIL.h"


#include "imgData.db"

static GLuint ttl,logo,bkgd,footer;






void drawtex(GLuint tex,float x,float y,float w,float h,float HZ,float VZ,float ts)
{
 
  glEnable( GL_TEXTURE_2D );
  glBindTexture( GL_TEXTURE_2D, tex );
 
 float tex_u_min = 0.0f,tex_u_max = 1.0f,tex_v_min = 0.0f,tex_v_max = 1.0f;
 
 tex_u_min =(1-HZ)/2;
 tex_u_max = 1 -  (1-HZ)/2;
 tex_v_min =(1-VZ)/2;
 tex_v_max = 1 -  (1-VZ)/2;
 
 
 glPushMatrix();
 glEnable( GL_BLEND );
 glEnable( GL_SMOOTH );
 glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
// glBlendFunc( GL_ONE, GL_ONE_MINUS_SRC_ALPHA );
 
 glColor4f( 1.0f, 1.0f, 1.0f, ts );

 glBegin(GL_POLYGON);
	glTexCoord2f( tex_u_min, tex_v_max );
	glVertex2f(x,y);

    glTexCoord2f( tex_u_max, tex_v_max );
    glVertex2f(x+w,y);

    glTexCoord2f( tex_u_max, tex_v_min );
    glVertex2f(x+w,y+h);

    glTexCoord2f( tex_u_min, tex_v_min );
    glVertex2f(x,y+h);
 glEnd();
 glPopMatrix();


 glDisable( GL_TEXTURE_2D );
 
}



void loadimg()
{
 #define memLDimg(x)  	SOIL_load_OGL_texture_from_memory((const unsigned char *const)x,sizeof(x),0,0,67);
 
 bkgd=memLDimg(bkd);
 ttl=memLDimg(ttd);
 logo=memLDimg(lgd);
 footer=memLDimg(ftd);
 
}



void paint()
{
 float rnd(float a,float b)
 {
 	return a+(float)(rand()%(int)(b-a));
 }
 
// const double t = glutGet(GLUT_ELAPSED_TIME) ;
 static double t;
 t+=50;
 
 glPushMatrix();
 	//glRotatef(3*rnd(-10,10),0,0,1);
	glRotatef(45*sin(t/500),0,0,1);
	drawtex(bkgd,-.7,-.8,1.4,1.5,.85,.85,.35);
 glPopMatrix(); 
 
 
 glPushMatrix();
 	glTranslatef(-1+.25,.7+.15,0);
 //	glRotatef(3*rnd(-5,5),0,0,1);
 //	glRotatef(9*rnd(-5,5),0,1,0);
 //	glRotatef(9*rnd(-5,5),1,0,0);
	glRotatef(3*5*sin(t/200),0,0,1);
 	glRotatef(9*5*sin(t/100),0,1,0);
 	glRotatef(9*5*sin(t/200),1,0,0);
	drawtex(logo,-.25,-.15,.5,.3,.97,.97,1);
 glPopMatrix();
 
 
 drawtex(ttl,-.5,.7,1,.3,1,.9,1);
 
 //drawtex(footer,-1,-1,2,rnd(10,25)/100,.97,.97,1);
 drawtex(footer,-1,-1,2,.1+.01*rnd(5,10)*sin(t/200),.97,.97,1);
 
}
