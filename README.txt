Jogo de Tabuleiro em C - Versão Aprimorada
Este é um programa em C que implementa um jogo de tabuleiro onde o jogador deve realizar movimentos específicos para eliminar peças do tabuleiro 8x8 até não ser mais possível fazer movimentos válidos ou até que o jogador decida encerrar o jogo.

Funcionalidades Implementadas:
Apresentação visual do tabuleiro e suas peças.
Verificação das possíveis jogadas a partir de uma posição indicada.
Verificação da derrota quando não há mais peças móveis.
Reinício do tabuleiro para um novo jogo.
Administração do jogo, permitindo movimentos válidos das peças.
Mensagens de parabéns de acordo com o desempenho do jogador.
Estrutura do Código:
O código está organizado em funções que realizam tarefas específicas:

exibe_tabuleiro(): Apresenta visualmente o tabuleiro atual e suas peças.
exibe_jogada(): Verifica as possíveis jogadas a partir de uma posição indicada.
verificando_derrota(): Verifica se ainda existem peças que podem se mover.
tabuleiro_n(): Restaura todas as peças para a posição inicial, iniciando um novo jogo.
funcao_jogo(): Função principal que administra o jogo, permitindo movimentos válidos das peças.
main(): Função principal onde o jogo é iniciado e o jogador pode escolher entre iniciar um novo jogo ou sair.
Como Jogar:
Ao iniciar o programa, escolha a opção 1 - Novo Jogo.
Escolha a linha e a coluna da peça que deseja mover.
Selecione a opção correspondente ao destino da peça, de acordo com as opções apresentadas.
Continue movendo as peças até não ser mais possível ou escolha 0 - Sair para encerrar o jogo.
Observações:
O programa foi desenvolvido em C e pode ser compilado e executado em um ambiente compatível com a linguagem.
O jogo apresenta diferentes níveis de dificuldade, baseados no desempenho do jogador em eliminar as peças.