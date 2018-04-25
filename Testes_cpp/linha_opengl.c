
#include <stdio.h>  //  libs para printf e tals
#include <stdlib.h> //   
#include <unistd.h> //  biblioteca para sleep	
#include<GL/glut.h> //  biblioteca opengl
#include<GL/gl.h>   //  biblioteca opengl
#include<math.h>    //  para simular uma senoide
#define COMP_MAX 720
#define ALTURA_MAX 480
#define MARG_ESQUERDA 50
#define MARG_DIREITA COMP_MAX-170
#define MARG_CIMA 450
#define MARG_BAIXO 50
#define pi 3.141592f



GLfloat Senoid[] = {
    MARG_ESQUERDA,200, // coordenada iniciais
    (MARG_ESQUERDA+1),200 
};

GLfloat Background[] = {

    MARG_ESQUERDA,50,MARG_DIREITA,50,   50,MARG_BAIXO,50,MARG_CIMA, 
    MARG_ESQUERDA,100,MARG_DIREITA,100, 100,MARG_BAIXO,100,MARG_CIMA,
    MARG_ESQUERDA,150,MARG_DIREITA,150, 150,MARG_BAIXO,150,MARG_CIMA,
    MARG_ESQUERDA,200,MARG_DIREITA,200, 150,MARG_BAIXO,150,MARG_CIMA,
    MARG_ESQUERDA,250,MARG_DIREITA,250, 200,MARG_BAIXO,200,MARG_CIMA,
    MARG_ESQUERDA,251,MARG_DIREITA,251, 250,MARG_BAIXO,250,MARG_CIMA,
    MARG_ESQUERDA,300,MARG_DIREITA,300, 300,MARG_BAIXO,300,MARG_CIMA,
    MARG_ESQUERDA,350,MARG_DIREITA,350, 350,MARG_BAIXO,350,MARG_CIMA,
    MARG_ESQUERDA,400,MARG_DIREITA,400, 400,MARG_BAIXO,400,MARG_CIMA,
    MARG_ESQUERDA,450,MARG_DIREITA,450, 450,MARG_BAIXO,450,MARG_CIMA,
                                        500,MARG_BAIXO,500,MARG_CIMA,
                                        550,MARG_BAIXO,550,MARG_CIMA,
                                        301,MARG_BAIXO,301,MARG_CIMA
                                        //600,MARG_BAIXO,600,MARG_CIMA,
};

void display() {
 // ------ Redimentionando a tela para pixels ---- // 
    glViewport(0.0f, 0.0f, COMP_MAX, ALTURA_MAX);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();   // update depois de mechar com a matriz 
    glOrtho(0, COMP_MAX, 0, ALTURA_MAX, 0, 1);  // setando os limites da tela
    glMatrixMode(GL_MODELVIEW); // default values
    glLoadIdentity();   //Sempre atualizar depois de setar funções de Matriz
// -----------------------------------------------//

    glClearColor(0,0,0,0);  // Cor preta no fundo da tela
    glClear(GL_COLOR_BUFFER_BIT);   // fechando o buffer
    
    glFlush();  // sempre que chamar essa função a tela é atualizada
    
    glEnableClientState(GL_VERTEX_ARRAY);   // habilita a escrita de um  array
    glColor3f(0.5f,0.5f,0.5f);  // cor cinza    
    glVertexPointer(2,GL_FLOAT,0,Background); // Dimensão, tipo, gap(0), coordenadas
    glDrawArrays(GL_LINES,0,(sizeof(Background)/2));
    
    //usleep(500000);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    
    glFlush();

    int i;
    //------------ Essa rotina funcionou---------------
    glLineWidth(3); // Espessura da linha (3 pixels)
    glColor3f(1.0f,1.0f,1.0f);  // cor branca    
    glEnableClientState(GL_VERTEX_ARRAY);

    for(i = 0; i < 500; i++){
        //teste com senoide
        Senoid[0] ++;   // incrementa a escala de tempo de acordo com a escala
        Senoid[2] ++;   // simulando o incremento de "amostras" recebidas   
        // OBS: A frequencia abaixo está em função da taxa de amostragem
        Senoid[1] = (int)(100*cos(2*pi*i/200)+250);     // senoide de teste com 0.5Hz
        Senoid[3] = (int)(100*cos(2*pi*(i+1)/200)+250); // senoide "amostrada" a 10ms depois 
        printf("senoid[0]: %.2f senoid[1]: %.2f senoid[2]: %.2f senoid[3]: %.2f\n",Senoid[0],Senoid[1],Senoid[2],Senoid[3]);
        //printf("senoid[1]: %.2f senoid[3]: %.2f\n",Senoid[1],Senoid[3]);
        glVertexPointer(2,GL_FLOAT,0,Senoid); // Dimensão, tipo, gap(0), coordenadas
        glDrawArrays(GL_LINES,0,2);           // O último número indica o número de vértices
        usleep(10000);  // taxa de amostragem (10ms).
        //if (i != 7)
        
        glFlush();
        
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    //glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    //glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    while(1);
    
}

void main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(300,100);
    glutInitWindowSize(COMP_MAX,ALTURA_MAX);
    glutCreateWindow("Osciloscope");
    glutDisplayFunc(display);
    glutMainLoop();
}
