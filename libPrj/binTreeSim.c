#include <stdio.h>
#include <math.h>
#include "GL/gl.h"
#include "GL/glut.h"

//#include <pthread.h>
#include <process.h>


#include "binTreeSim.h"

typedef int item;


typedef struct bintree
{
	item d;
	struct bintree *l;
	struct bintree *r;
	int extra[3];
} gtree;


static char opfmt[17]="%2d";

void setopfmt(char *x)
{ sprintf(opfmt,"%s",x); /*puts(opfmt);*/	}



static char rdflag;


void drawtex(GLuint tex,float x,float y,float w,float h,float HZ,float VZ,float ts);
void loadimg();





void init(void *rtp)
{
  static float dy=0.2,tx=0.003;
  static gtree **mt;
  static char firstrun;

  mt=(gtree **)rtp;

 if(!firstrun)
 {
  void glutMachineStart(void *x)
  {


   void display()
   {
    static float wd,ht;

/**/void line(float x1, float y1,float x2, float y2,float pt)
	{
	 glLineWidth(pt);
	 glBegin(GL_LINES);
	 	glVertex2f(x1,y1);
	 	glVertex2f(x2,y2);
	 glEnd();
	 glLineWidth(1);
	}



/**/void ellipse(float ox,float oy,float a,float b)
	{
	 float x,y,i;
	 glBegin(GL_POLYGON);
		for(i=0;i<=100;i+=8)
		{
			x=ox+a*cosf(i*2*M_PI/100);
			y=oy+b*sinf(i*2*M_PI/100);
			glColor3f(i,i,155+i);
			glVertex2f(x,y);
		}
	 glEnd();
	}


/**/int gprintf(float x, float y, GLfloat scale, char* format, ...)
	{
	    va_list args;
	    char buffer[255], *p;
	    static GLfloat font_scale = 119.05 + 33.33;

	    va_start(args, format);
	    int len=vsprintf(buffer, format, args);
	    va_end(args);
		wd=glutGet(GLUT_WINDOW_WIDTH);
		ht=glutGet(GLUT_WINDOW_HEIGHT);

	    glMatrixMode(GL_PROJECTION);
	    glPushMatrix();

	    gluOrtho2D(-wd*.5, wd*.5, -ht*0.5, ht*0.5);

	    glMatrixMode(GL_MODELVIEW);
	    glPushMatrix();

	    glTranslatef(x*wd*.5, y*ht*.5, 0.0);

	    scale*=( wd<ht? wd : ht );
	    glScalef((scale/font_scale)*(wd/512), (scale/font_scale)*(ht/512), scale/font_scale);

	    glLineWidth(2.5*(scale/20)*( wd<ht? (wd/512) : (ht/512) ));
		glTranslatef(-font_scale*0.6874*len*.5, -font_scale*0.2187, 0.0);
	    for(p = buffer; *p; p++)
	        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);

	    glPopMatrix();
	    glMatrixMode(GL_PROJECTION);
	    glPopMatrix();
	    glMatrixMode(GL_MODELVIEW);

	    return len;
	}


/**/void drawnode(float x,float y,item z,float d)
	{
	    glColor3f(0,0,0);
		ellipse(x,y,.17/d,.15/d);

	    glColor3f(0,.8,0);
		gprintf(x,y,.08/d,opfmt,z);
	}

/**/void drawinorder(gtree *root,float xl,float xh,float y)
	{
	 static float d;
	 if(root)
	 {
	 	d++;
	 	float m=(xl+xh)/2 ;
	 	xl+=tx; xh-=tx;

	    glColor3f(1,0,0);
	 	if(root->l)
		  line(m,y,(xl+m)/2,y-dy,2.5);
	 	if(root->r)
		  line(m,y,(m+xh)/2,y-dy,2.5);

		drawinorder(root->l,xl,m,y-dy);
 		drawnode(m,y,root->d,d);
 		drawinorder(root->r,m,xh,y-dy);

	 	d--;
 	 }
    }






	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	paint();
    glColor3f(1,0,0);
	
	
	drawinorder( mt?*mt : 0  ,-1,1,.5);

    glutSwapBuffers();
  }


	 void kbd(unsigned char key,int x,int y)
	 {
	  static char fullscreen;
	  switch (key)
	  {
		case 27 :
	    case 'q':
	             exit(0);
	             break;

	    case 'f':
		case 'F':
				 fullscreen=!fullscreen;
				 if(fullscreen)
		             glutFullScreen();
		         else
		         {
			  		glutPositionWindow(10,30);
             		glutReshapeWindow(640,480);
  		     	 }
	             break;

	  }
	  glutPostRedisplay();
 	 }

	 void refresh(int t)
 	 {

		if(rdflag)
		{
			display();//glutPostRedisplay();
			rdflag=0;
			t=50;
		}
		glutTimerFunc(t,refresh,t+10);
 	 }


 	 static int argc=1;
 	 static char *argv[]={"Programmer Panda"};





	 glutInit(&argc, argv);

	 glutInitWindowPosition(10,10);
 	 glutInitWindowSize(640,480);

     glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE| GLUT_DEPTH);

     glutCreateWindow("Tree Simulator v1.5 by Programmer Panda");
     glClearColor(1,1,1,0);


	 glutDisplayFunc(display);
	 glutKeyboardFunc(kbd);

	 //glutIdleFunc(glutPostRedisplay);
	 refresh(500);
	 loadimg();
	 firstrun=!firstrun;
	 glutMainLoop();
	 printf("Machine Stopped\n");
  }




 //  pthread_create_np(malloc(sizeof(pthread_t)),0,(void (*)(void *))glutMachineStart,0);
//    CreateThread(0,0,(LPTHREAD_START_ROUTINE) glutMachineStart,0,0,0);
	_beginthread(glutMachineStart,0,0);

   while(!firstrun);
 }

 rdflag=1;

}



void redraw()
{ rdflag=1;   }











