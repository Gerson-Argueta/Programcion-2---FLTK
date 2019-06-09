//Nombre: Gerson Rene Argueta Martinez
//Carnet: AM18047

//Librerias obligatorias para que el programa trabaje en un entoro grafico.
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/fl_message.H>
#include <FL/Fl_Round_Button.H>
#include <stdio.h>
#include <string.h>

//Se define como se llamara el archivo y se le asigna la extencion [.txt.], para que se cree en en formato de texto.
#define ARCHIVO "clientes.txt"

//Se crea la clase
class Cliente: public Fl_Window 
{
	//Estos son los atributos con los cuales se trabajara. 
	Fl_Input  *ent_Cod;
	Fl_Input  *ent_Nom;
	Fl_Input  *ent_Ape;
	Fl_Input  *tx;
	Fl_Round_Button  *ent_Bg;
	Fl_Round_Button  *ent_Bs;
	Fl_Button *b1;
	Fl_Button *b2;

	public:
		//estos son los metodos con los cuales se trabajara.
		Cliente() : Fl_Window(600,350) 
		{
			begin();

            ent_Cod= new Fl_Input(80,20,250,24,"CODIGO:");
            ent_Nom= new Fl_Input(80,40,250,24,"NOMBRE:");
            ent_Ape= new Fl_Input(80,60,250,24,"APELLIDO:");
			tx= new Fl_Input(80, 100, 0, 0, "SEXO:");
            ent_Bg=  new Fl_Round_Button(100, 80, 40, 40, "F");
            ent_Bs=  new Fl_Round_Button(180, 80, 40, 40, "M");
            b1=new Fl_Button(80,160,100,25,"Guardar");
            b2=new Fl_Button(200,160,100,25,"Salir");
            b1->color(FL_CYAN);
	       	b2->color(FL_RED);
	     	end();
            b1->callback(Boton_CB, (void*)this);
            b2->callback(Boton_CB, (void*)this);
            ent_Bg->callback(Boton_CB, (void*)this);
            ent_Bs->callback(Boton_CB, (void*)this);
       
		} 

		static void Boton_CB(Fl_Widget *w, void *data) 
		{
        	Cliente *e = (Cliente*)data;

			if ( strcmp(w->label(), "F") == 0 ) 
			{
      				e->SetM(0);
			}

			if( strcmp(w->label(), "M") == 0 ) 
			{
				e->SetF(0);
			}

			if ( strcmp(w->label(), "Guardar") == 0 ) 
			{
				if ( e->Guardar(ARCHIVO) == 0 ) 
				{     
					fl_message("%s", "los datos se guardaron");       
            	}
				else
				{ 
		         	fl_message("%s", "los datos no se guardaron");
				}
			}

			if ( strcmp(w->label(), "Salir") == 0 ) 
			{
				e->hide();
			}

      
 		} 

		int Guardar(const char *nombrearchivo)
		{
			FILE *fp = fopen(nombrearchivo, "a+");
	
	        if ( !fp ) {
	            fl_message("%s", "error no se puede abrir el archivo");
	            return -1;
			}
	
	         fl_message("%i", ent_Bg->value());

	      	if( ent_Bg->value()==0)
			{
				fprintf(fp, "%s %s %s M\n ", ent_Cod->value(),ent_Nom->value(),ent_Ape->value());
	        }

			if( ent_Bs->value()==0)
	        {
				fprintf(fp, "%s %s %s F\n ", ent_Cod->value(),ent_Nom->value(),ent_Ape->value());
	        }


	      	fclose(fp);
	       	return 0;
		}


		void SetF(int val)      
		{        
	    	ent_Bg->value(val);
	 	}
	
		void SetM(int val)      
		{        
		    ent_Bs->value(val);
		}

		void SetCodigo(const char *val)      
		{        
		    ent_Cod->value(val);
		}
 
		const char *GetCodigo() const 
		{ 
			return ent_Cod->value();   
		}

		void SetNombre(const char *val)      
		{        
	    	ent_Nom->value(val);
		}
    
		const char *GetNombre() const 
		{ 
			return ent_Nom->value();   
		}

		void SetApellido(const char *val)      
		{        
	    	ent_Ape->value(val);
		}

		const char *GetApellido() const 
		{ 
			return ent_Ape->value();   
		}

};

//Esta es la funcion principal
int main() 
{
	
     Cliente *e = new Cliente();

     e->show();
     return Fl::run();
} 

