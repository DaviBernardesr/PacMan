Projeto Pacman (Orientado a Objetos)

Descrição:
Este projeto é uma implementação do clássico jogo Pacman utilizando a biblioteca Allegro para criação de jogos em C++. 
O jogo consiste em controlar o personagem Pacman, movendo-o pelo labirinto para coletar todas as pílulas e evitar os inimigos.

Autor:
Davi Bernardes Oliveira Ribeiro

Requisitos:
Allegro 5.0 ou superior
Compilador C++ (GCC, Clang, MSVC, etc.)

Diretórios e Arquivos:
Pacman/
headers/
Bloco.h
Pilula.h
Pacman.h
Inimigos.h
InimigosAleatorios.h
InimigosInteligentes.h
Movimentacao.h
assets/
images/
pacman.png
InimigosT.png
fundo.png
fonts/
Roboto-Regular.ttf
src/
main.cpp

Compilação e Execução:
Certifique-se de ter a biblioteca Allegro instalada.

Compile o projeto utilizando o seguinte comando (exemplo para GCC):
Copiar código: g++ -o Pacman src/main.cpp -lallegro -lallegro_image -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_native_dialog

Execute o jogo:
Copiar código: ./Pacman

Funcionalidades:

Mapa do Jogo:
O jogo é composto por uma matriz 2D que define a estrutura do labirinto:
0 representa blocos.
1 representa pílulas.
2 representa áreas específicas, possivelmente pontos de spawn de inimigos ou áreas especiais.

Personagens e Objetos:
Pacman: Controlado pelo jogador, deve coletar todas as pílulas e evitar os inimigos.
Inimigos: Existem dois tipos de inimigos no jogo, InimigosAleatorios e InimigosInteligentes, cada um com seu comportamento específico.
Controles

Setas do teclado:
Movem o Pacman na direção desejada.
Esc: Encerra o jogo.

Pontuação:
A pontuação é exibida na parte inferior da tela, indicando quantas pílulas foram coletadas.

Código Principal:
O arquivo main.cpp contém a lógica principal do jogo, incluindo:
Inicialização da biblioteca Allegro.
Criação e configuração da janela de jogo.
Loop principal do jogo, que inclui detecção de eventos, movimentação dos personagens e renderização dos gráficos.
Verificação de colisões entre o Pacman e os inimigos.

Dependências:
O projeto depende das seguintes bibliotecas Allegro:
allegro
allegro_image
allegro_primitives
allegro_font
allegro_ttf
allegro_native_dialog

Contribuições:
Contribuições são bem-vindas! Para contribuir, faça um fork do projeto, crie um branch para suas alterações e envie um pull request.

Licença:
Este projeto está licenciado sob a MIT License. Para mais informações, consulte o arquivo LICENSE.