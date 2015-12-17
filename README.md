## ALGORITMO DE FORÇA BRUTA EM C 

### LICENÇA
**MIT**
[Leia a licença](LICENSE)

### COMPILADOR UTILIZADO
***GCC (TDM-1) 4.7.1 -> Windows***

### OBJETIVO
Demonstrar o funcionamento do algoritmo de força bruta.

### Notas:
*Esse algoritmo foi desenvolvido apenas para fins educativos.*

### COMO USAR
Basicamente irá chamar a função *bruteForce()* com seus respectivos parâmetros. São eles:
- int leng: Aqui se passa o tamanho da frase, no caso de não saber deve-se passar -1.
- int opt: Aqui se passa o número de uma das opções de procura.
  - opt = 1: Quando se deseja testar apenas com números;
  - opt = 2: Quando se deseja testar apenas com letras; 
  - opt = 3: Quando se deseja testar apenas com letras e números;
  - opt = 4: Quando se deseja testar com letras, números e caracteres especiais;
- char *prog: Aqui se passa o nome do programa que irá verificar a combinação gerada com a senha. No caso de não saber o nome do programa passe esse parâmetro como NULL.
