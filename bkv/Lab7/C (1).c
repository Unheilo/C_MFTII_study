#include <cairo/cairo.h>
#include <gtk/gtk.h>
#include <ctype.h>
#include <gdk/gdkkeysyms.h>
#include "matrix.h"
#include <stdio.h>

#define N 100000

#define DEBUG
#undef DEBUG

#include <glib/gi18n.h>

guint threadID = 0;
   FILE *I;   char ANY[20], *fname;

MATRIX Rx, Ry, Rz, T1, T2, Pe, Rs, P, Vec;
  GtkWidget *window;
typedef struct atom{
   double xyz[4];
   char name[10];
   int R;
double RED;
double BLUE;
double GREEN;
} ATOM;


ATOM at[N];
int n, from[N], to[N];
    int Nat, Nl, any, Label=0, Hydr=1; double Any;

double Scale=100.0, Rscale=100.0,
                    Xc=0.0, Yc=0.0, Zc=0.0, m, M=0.0;
     gint  XC, YC, ZC;
double Alpha=0.0, Beta=0.0, Gamma=0.0;
double dAlpha=0.0, dBeta=0.0, dGamma=0.0;

double XX[N], YY[N], ZZ[N];

static gboolean
serial_data (gpointer user_data)
{
    Alpha+=dAlpha;
    Beta+=dBeta;
    Gamma+=dGamma;
}
void setP() 
{  
 MATRIX PA, PB, PP;
  gtk_window_get_size((GtkWindow *)window, &XC,&YC);  
  XC/=2; YC/=2;
  PP=mat_creat(4,4,UNIT_MATRIX);
  mat_fill_x(Rx, Alpha);
  mat_fill_y(Ry, Beta);
  mat_fill_z(Rz, Gamma);
  mat_fill_s(Rs, Scale);
  mat_fill_t(T1, -XC, -YC, -ZC);
  mat_fill_t(T2,  XC,  YC,  ZC);
  PB = mat_mul(PP,Rx);
  PA = mat_mul(PB,Ry);
  PB = mat_mul(PA,Rz);
  PA = mat_mul(PB,Rs);
  PB = mat_mul(PA,T2);
  for (int i=0; i<Nat; i++)
    {  
     Vec[0][0] = at[i].xyz[0];
     Vec[0][1] = at[i].xyz[1];
     Vec[0][2] = at[i].xyz[2];
     Vec[0][3] = at[i].xyz[3]=1;
       PP = mat_mul(Vec, PB);
       XX[i] = PP[0][0]/PP[0][3];  // координаты после преобразования  
       YY[i] = PP[0][1]/PP[0][3];
       ZZ[i] = PP[0][2]/PP[0][3]; 
   }
 }

gboolean
on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data);

gboolean timeout(GtkWidget *widget)
{
    gtk_widget_queue_draw(widget);
    return TRUE;
}

static void do_drawing(cairo_t *);

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    gpointer user_data)
{
  do_drawing(cr);
   threadID = g_timeout_add(250, serial_data, user_data);

  return FALSE;
}

static void do_drawing(cairo_t *cr)
{
  cairo_set_line_width(cr, 2.0);
  int i, j; double R,r; int RR,GG,BB;
 setP();
 cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
		                   CAIRO_FONT_WEIGHT_NORMAL);
 cairo_set_font_size (cr, 30.0);
  for (i = 0; i < Nat; i++ ) {
          cairo_arc(cr, XX[i], YY[i], at[i].R*Scale/Rscale, 0, 2 * 3.14159);
	  cairo_move_to(cr,XX[i]+R*(Scale+5), YY[i]-R*(Scale+5));
		  cairo_set_source_rgb (cr,1,1,1);
		  if (Label)
	    for (i = 0; i < Nl; i++ ) {
             cairo_move_to(cr, XX[from[i]-1], YY[from[i]-1]);
             cairo_line_to(cr, XX[to[i]-1],   YY[to[i]-1]);
            cairo_stroke_preserve(cr);    
            }
  cairo_stroke_preserve(cr);    
}

void Input_from_file(char *f)
{
	if (I) fclose(I);
    I=fopen(f,"r");
    if (I==NULL)
     {
                 printf("File %s open ERROR\n",f);
                 exit (-1);
         }
    fscanf(I,"%d%d",&Nat, &Nl);
    for(int i=0; i<Nat; i++)
     {  
               fscanf( I, "%d%s%lf%lf%lf%lf",&any,at[i].name,
                    &at[i].xyz[0], &at[i].xyz[1], &at[i].xyz[2],&Any);
	       printf("%s\n",at[i].name);
	       switch( tolower(at[i].name[0]))
	         { case 'h':
		   case '~': m=1;
		      at[i].R=4; at[i].RED=0.9;
		      at[i].BLUE=0.9; at[i].GREEN=0.9;  break;
	           case 'c': m=12;  
		      at[i].R=12; at[i].RED=145./255;
		      at[i].BLUE=145./255; at[i].GREEN=145./255;  break;
	           case 'o': m=16;   
		      at[i].R=14; at[i].RED=240./255;
		      at[i].BLUE=0; at[i].GREEN=0;  break;
	           case 'n': m=15; 
		      at[i].R=10; at[i].RED=143./255;
		      at[i].BLUE=143./255; at[i].GREEN=1./255;  break;
	           case 's': m=32;
		      at[i].R=20; at[i].RED=1.0;
		      at[i].BLUE=199./255; at[i].GREEN=48./255;  break;
	           case 'p': m=31;
		      at[i].R=30; at[i].RED=255./255;
		      at[i].BLUE=128./255; at[i].GREEN=0;  break;
	           case 'f': m=56;
		      at[i].R=50; at[i].RED=230./255;
		      at[i].BLUE=77./255; at[i].GREEN=0;  break;
	           case 'z': m=65.4; break;
		   default: m=30; 
		      at[i].R=12; at[i].RED=16./255;
		      at[i].BLUE=66./255; at[i].GREEN=145./255;  
		  }
	       Xc+=at[i].xyz[0]*m;
	       Yc+=at[i].xyz[1]*m;
	       Zc+=at[i].xyz[2]*m;
	       M+=m;
         }
         Xc/=M; Yc/=M; Zc/=M;
    for(int i=0; i<Nat; i++){
	   at[i].xyz[0]-=Xc; 
	   at[i].xyz[1]-=Yc; 
	   at[i].xyz[2]-=Zc; 
    }
     for(int i=0; i<Nl; i++)
     {  
               fscanf( I, "%d%d%d%s",&any, &from[i],&to[i],ANY);
         }
}
int main(int argc, char *argv[])
{
   Rx = _mat_creat(4,4);
   Ry = _mat_creat(4,4);
   Rz = _mat_creat(4,4);
   T1 = _mat_creat(4,4);
   T2 = _mat_creat(4,4);
   Pe = _mat_creat(4,4);
   Rs = _mat_creat(4,4);
   P  = _mat_creat(4,4);
   Vec = _mat_creat(1,4);  Vec[0][3]=1;
    fname=argv[1];
    Input_from_file(fname);
  GtkWidget *darea;
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  darea = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), darea);
 
  gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);

  g_signal_connect(G_OBJECT(darea), "draw", 
      G_CALLBACK(on_draw_event), NULL); 
  g_signal_connect(window, "destroy",
      G_CALLBACK(gtk_main_quit), NULL);  
  g_signal_connect (G_OBJECT (window), "key_press_event", G_CALLBACK (on_key_press), NULL);
    
   g_timeout_add(1, (GSourceFunc)timeout, window);
 
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 800); 
  gtk_window_set_title(GTK_WINDOW(window), "MOLECULE");
    XC=400; YC=400;  ZC=0;
  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

gboolean
on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
  switch (event->keyval)
  {
    case GDK_KEY_plus:
      Scale*=1.1; setP();
      break;
    case GDK_KEY_minus:
      Scale*=0.9; setP();
     break;
    case GDK_KEY_S:
    case GDK_KEY_Right:
       dBeta-=0.01; setP();
       break;
    case GDK_KEY_s:
    case GDK_KEY_Left:
       dBeta+=0.01; setP();
      break;
    case GDK_KEY_a:
    case GDK_KEY_Down:
       dAlpha-=0.01; setP();
       break;
    case GDK_KEY_A:
    case GDK_KEY_Up:
       dAlpha+=0.01; setP();
      break;
    case GDK_KEY_space:  // Stop motion
       dAlpha=dBeta=dGamma=0;
       setP(); break;
    case GDK_KEY_0:  //  initial coords
       Alpha=Beta=Gamma=0;
       setP(); break;
    case GDK_KEY_x:  // eXit - Quit keys
    case GDK_KEY_X:
    case GDK_KEY_q:
    case GDK_KEY_Q:
           exit(0);
    default:
      return FALSE;
  }

  return FALSE;
}


