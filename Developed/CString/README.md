# LerStringEmC
/********************************************************************************************************+
|	Autor: Edimar Calebe Castanho									 |
|													 |
|Este Código pode Ser utilizado para Ler Strings com um menor risco de estouro de Buffer.		 |
|Não é um código 100% revisado, porém apresentou resultados satisfatórios nos testes.			 |
|													 |
|Para se utilizar deste código. O seu ponteiro deverá impreterívelmente ser uma variável Global.         |
|Caso contrário o conteúdo da sua String será NULL, a menos que você acesse o seu conteúdo               |
|somente dentro da Função 'lestring()' 									 |
|													 |
|#Protótipo:	char *lestring(int min, int max); 							 |
|Função Recebe como parâmetros dois inteiros, um deles serve para comparar o tamanho mínimo da String,   |
|e o outro compara o tamanho máximo da string. Se esses valores forem desobedecidos a função retorna ao  |
|início da função e realiza a leitura novamente.  							 |
|													 |
|#Se o Valor máximo for passado com valor igual a 0(zero), o mesmo é assumido como o valor do Buffer,    |
|ou seja, valor muito grande.										 |
+********************************************************************************************************/

