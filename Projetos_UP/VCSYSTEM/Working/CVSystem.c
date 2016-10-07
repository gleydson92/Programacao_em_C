#include<ncurses.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
void data_hora()
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  //printf ( "The current date/time is: %s", asctime (timeinfo) );
}
void start()
{
  has_colors();
  start_color();
}
void menu()
{
  move(0,0);
  initscr();
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_CYAN);
  attrset(A_BOLD | COLOR_PAIR(1));
  bkgd(COLOR_PAIR(1));
  attron(A_UNDERLINE);
  printw("SISTEMA DE SUPERMERCADO!\t");
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printw("%s\n",asctime (timeinfo));
  int selec;
  attrset(A_BOLD);
  printw("*Para selecionar uma opção digite:\n");
  printw("\t1-) Categorias;\n\t2-) Alterar/Excluir Cadastros;\n\t3-) Formulário de Vendas;\n\t4-) Fechamento de Caixa\n\t5-) Sair\n");
  scanw("%d",&selec);
  getchar();
  switch(selec){
      case 1:
          system("clear");
          //cadastro();
          break;
      case 2:
          system("clear");
          //listagem();
          break;
      case 3:
          printw("Este menu é para Listar as Prioridades de Serviços!\n");
          system("clear");
          //listaprioridades();
          break;
      case 4:
          system("clear");
          // exit(EXIT_SUCCESS);
          break;
      default:
          system("clear");
          menu();
  }
  refresh();
}
void padaria()
{

}
void cadastroitens()
{

}
void estoque()
{

}
int main(void)
{
  //data_hora();
  //start();
  setlocale(LC_ALL,"");
  menu();
  getchar();
  endwin();
}
