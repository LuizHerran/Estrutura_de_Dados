<h1>Visão Geral</h1>
<p>Este programa em C realiza a leitura de um arquivo .csv contendo dados de filmes,
armazena essas informações em uma estrutura de dados (struct) e permite ordenar
os filmes com base em diferentes critérios: nome, categoria, nota e duração, e pode
exportar os dados processados, novamente para um arquivo .csv.</p>

<h2>Bibliotecas Utilizadas</h2>
<p>• stdio.h: operações de entrada/saída.</p>
<p></p>• stdlib.h: funções utilitárias (alocação de memória, conversões, etc.).
<p></p>• string.h: manipulação de strings.

<h2>Estruturas Utilizadas</h2>
<p></p>• nome: Nome do filme.
<p></p>• categoria: Categoria/ gênero do filme.
<p></p>• nota: Nota de avaliação do filme.
<p></p>• duração: Duração do filme (em horas e minutos).

<h2>Definições</h2>
<p></p>• MAX_FILMES: quantidade máxima de filmes (100).
<p></p>• TAM_NOME_FILME: tamanho máximo do nome do filme (30 caracteres).
<p></p>• TAM_NOME_CATEGORIA: tamanho máximo do nome da categoria (12 caracteres).

<h2>Funções Principais</h2>
<h3>int charToAscii(char c)</h3>
<p></p>• Converte um caractere em seu valor ASCII.
<p></p>• Auxilia na comparação entre caracteres nas funções de ordenação.
<h3>int recuperarConteudoExcel(Filme filmes[])</h3>
<p></p>• Lê os dados do arquivo dados.csv.
<p></p>• Armazena cada linha em um elemento do vetor de Filme.
<p></p>• Ignora a primeira linha do arquivo (cabeçalho).
<p></p>• Retorno: quantidade de filmes lidos.
<h3>void mostrarDadosOrdenados(Filme filmes[], int qtd)</h3>
<p></p>• Exibe na tela as informações de todos os filmes cadastrados.
<p></p>• Formata a duração no padrão "XhYmin".

<h2>Funções de Ordenação</h2>
<p></p>Todas as funções de ordenação implementam o algoritmo Bubble Sort, personalizado para lidar com a estrutura Filme, tal função também foi feita para analisar o nome do
filme letra a letra. Durante a ordenação, sempre que dois filmes trocam de posição, todos os campos (nome, categoria, nota, duração) são trocados simultaneamente, tornando a função cada vez mais a prova de falhas.
<h3>void ordenarFilmesPorNome(Filme filmes[], int qtd)</h3>
<p></p>• Ordena os filmes em ordem alfabética com base no nome do filme.
<p></p>• Comparação é feita caractere por caractere usando valores ASCII.
<h3>void ordenarFilmesPorCategoria(Filme filmes[], int qtd)</h3>
<p></p>• Ordena os filmes em ordem alfabética com base na categoria (gênero).
<h3>void ordenarFilmesPorAvaliacao(Filme filmes[], int qtd)</h3>
<p></p>• Ordena os filmes da nota mais baixa para a mais alta.
<h3>void ordenarFilmesPorDuracao(Filme filmes[], int qtd)</h3>
<p></p>• Ordena os filmes do mais curto para o mais longo, considerando a duração em minutos.

<h2>Arquivo de Entrada - dados.csv</h2>
<p></p>• Formato esperado: Nome, Categoria, Nota, Duração
<p></p>Filme A, Aventura, 8.5,120
<p></p>Filme B, Drama, 7.2, 90
<p></p>Filme C, Comédia, 6.8,110
<p></p>• Cada linha representa um filme.
<p></p>• As colunas são separadas por vírgula.

<h2>Problemas Encontrados</h2>
<p></p>O nosso código teve de ser modificado posterior a um erro encontrado, quando
executado, não havia precisão na ordenação por números, o que foi modificado na nova
versão.

<h2>Funcionamento</h2>
<p>1. O programa vai ler os dados de filmes de um arquivo CSV.</p>
<p>2. O usuário escolhe o critério de ordenação.</p>
<p>3. Os filmes são ordenados conforme a escolha do usuário.</p>
<p>4. O resultado pode ser exibido e posteriormente exportado para um novo CSV.</p>
