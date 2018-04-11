# Projeto-controle-de-estoque-para-um-boate
  Por meio deste projeto procura-se elaborar um gerenciador de uma boate , que efetuara os serviços de bar e dança e demais, contudo a mesma a apresenta a opção de aluguel do espaço fisico para festas tematicas.
  A boate funcionara normalmente também sem o estabelecimento estar alugado , promovendo eventos e shows necessitando asssim de funcionarios do tipo barman, faxineira, dançarina cantor ou DJ e um gerente para administrar o negocio, os clientes possuiram um código de acesso, caso o cliente for frequentador assíduo pode optar por ser tornar vip. O cliente vip tem vantagens relacionadas a descontos, promoções e vales na boate. Ressalta-se também que o cliente que for estudante e maior de 18 anos terá desconto com carteirinha de estudante.
    A implmentação deste programa vem para facilitar e ajudar a gerenciar os fluxo de vendas, serviços, estoque e alugueis prestados pela boate, por intermedio de classes e suas respectivas propriedades em linguagem C++.
# Descrição
  Por intermédio de da classe boate será executada as operações de comercias de uma loja, contudo todo o estabelecimento comercial necessita de funcionários para realizar os serviços prestados pela Boate além é claro de clientes, logo cria-se classes filhos de Boate denominadas de Funcionário e Cliente nos quais ambas herdam os atributos e funções de Boate.
  Entretanto todo o funcionário e cliente é uma pessoa neste caso, portanto é necessário criar uma classe abstrata para servir como modelo chama-se ela de Pessoa, essa servira para inserir os dados pessoas e bancários de uma pessoa, que neste problema será cliente ou funcionário.
    Partindo de funcionário é necessário entender que existem dentro de uma empresa diferentes tipos de funcionários que exercem diferentes funções dentro de uma empresa, logo trazendo isso para a Boate temos que existem nela um Barman um DJ ou Cantor um gerente, faxineira, dançarina, sendo este os funcionários pertencentes a nossa boate, contudo nota-se que possui uma relação com funcionários, mas com diferentes funções para respectivos serviços portanto é necessário criar uma classe para cada tipo de funcionário , ressalta-se que essas classes serão filhos de funcionários.
      A classe Dançarina, Gerente e Cantor/DJ são pessoas que trabalham na boate, então as heranças estão corretas, cada classe irá executar as devidas atribuições de sua profissão, vista disso serão associadas com a classe boate por meio do gerenciamento de venda, musica entre outros.
        A função barman e limpeza apresenta-se dentro da classe Funcionário devido não possuírem atribuições especiais. A função Barman irá apenas manipular os dados de estoque de bebida e receita de bebida da classe boate, sendo assim não é necessário criar uma classe para ela, enquanto a função limpeza servira apenas dizer que existe uma faxineira que é uma pessoa que trabalha para boate e recebe um determinado valor. Ressalta-se que a diferença deste funcionário para os outros funcionários que foram colocados em classes é o fato de novas funções que estes funcionaram exerceram.
        Uma empresa só consegue existir se possuir clientes é logico, e assim como foi relatado acima todo o cliente é pessoa, mas uma pessoa só é cliente se esta possui algum vínculo ou dependência de alguma empresa, devido a isso a Classe Cliente é filho de Boate, contudo os clientes irão usufruir dos benefícios da empresa, nos quais são executados por seus funcionários, desse modo existe um vínculo de amizade entre Cantor/DJ e Dançarina, não são filhos, pois não necessidade de que Cantor/ DJ ou Dançarina herdem atributos de pessoas novamente e atributos de Cliente, apesar de serem classes amigas queremos apenas identificar o cliente no qual está sendo executado o pedido, devido a isto são amigos não iremos manipular os atributos de Cliente apenas ter acesso.
        A classe dançarina irá representar as funções que uma dançarina exerce numa boate, por intermédio dela será gerenciado as danças prestadas na festa e o valor arrecadado além é claro de habilidades especiais que a dançarina possa ter.
        A classe Cantor/DJ representa o funcionário responsável pela música da boate, este pode executar uma seleção de música pré-selecionada pelo cliente, como executar uma seleção qualquer da boate.
       
   # classe Boate
   A classe Boate se refere tanto ao estabelecimento físico, como a parte de dados econômicos e estoque,
   
   
          GET_ CONTAS
   
   Nesta função serão adicionadas as contas da boate, referente a energia, bebidas, pagamentos de funcionários, água entre outras.
   
      GET_ EVENTOS
      
Por meio desta função serão agendados os eventos da boate, apresentando a data do evento, a quantidade de pessoas da festa a hora de início e final da festa e o tema da festa.

    GET_ECONOMIA

Por intermédio desta função serão calculados os lucros e as receitas da boate.

        GET_RECEITASBEBIDAS
        
Temos uma função especial para bebidas devido ao Barman possuir um caixa, logo controla-se o retorno financeiro de bebidas para uma melhor analise de quantos se deve comprar de bebidas e qual tipo está rendendo mais.

      GET_BEBIDAS
      
Esta função terá como objetivo adicionar as bebidas e seus respectivos nome e marca para um controle maior do bar.

# 2. Classe Pessoa
Está será uma classe abstrata, logo irá funcionar apenas como modelo para preenchimento de clientes e funcionários. A seguir apresenta-se a funções da classe.

    GET_DADOSPESSOAIS

Por meio desta função será preenchido os dados pessoais como RG, CPF, endereço, e-mail, sexo, telefone, CEP.

    GET_DADOSBANCARIOS

Apresenta-se uma função especifica para dados bancários pois esta pode ser optativa para cadastro do cliente, enquanto que para os funcionários ela se torna relevante em razão que por intermédio dela poderá efetuar os pagamentos diretos em conta.

  # 3. Classe Funcionário
Está classe é derivada das Classes Boate e Pessoa, logo apresenta as seguintes funções:

    GET_SALARIO
    
Como o próprio nome já deixa claro, função tem está que tem como objetivo inserir o salário do funcionário, fizemos a parte devido existir funcionários que serão apenas contratados por uma festa logo terá seu salário fixo enquanto outros terão comissão.
  
    GET_EXPEDIENTE

Por meio desta função o funcionário irá adicionar seu expediente de serviço, colocando assim os horários para análise do gerente.

    GET_TEMPODECONTRATO

Por intermédio desta função serão inseridos os tempos de contratos que podem ser de uma festa até meses anos.

    GET_BARMANDADOS
    
Está será uma função especifica dentro da classe Funcionários, aonde será apenas preenchido os dados do barman

    GET_BARMAN
  
  Função especifica do Barman que tem como objetivo gerenciar o bar, a venda e o estoque de bebidas assim como atribuição de nomes.
  
    GET_LIMPEZADADOS

Apresenta-se também como uma função especifica da classe para limpeza da boate, logo será apenas para preenchimentos dos dados pessoais e bancários e horários de serviço tempo de contrato, pois esses dados são importantes para economia da boate.
# 4. Classe Cliente
Classe derivada de Boate e Pessoa, nesta classe servira caso o cliente deseje alugar o espaço físico da boate, como também ele deseje apenas usufruir da boate em um dia normal, apresentando seu código e seu extrato referente ao uso. A seguir apresenta-se a funções da classe.

    GET_CLIENTEVIP
    
Está função apresenta os clientes que são Vips, logo eles possuem vantagens com relação aos clientes normais.
# 5. Classe Cantor ou DJ
Está e derivada de funcionários e amiga da Classe Cliente, pois o cliente pode escolher a seleção das músicas que serão tocadas na boate além e claro de cantor ser um funcionário da boate. A seguir apresenta-se a funções da classe.

    GET_MUSICAS
    
Função que tem o objetivo de inserir as músicas as desejadas para o evento.
# 6. Classe Dançarina
Classe derivada de Funcionários e amiga de Clientes, está classe irá apresentar as funções e serviços da Dançarina, aonde a mesma ira gerenciar os serviços que ela efetuou. A seguir apresenta-se a funções da classe.

    GET_DANÇA
    
Função destinada a inserção de quais tipos de dança a dançarina irá fazer na festa.

    GET_RECEITADANÇA
    
Função destinada inserção do valor conquistados com a dança na festa.

    GET_SERVIÇOS
    
Função destinada a inserção de quais habilidades a adicionais a dançarina possui e o valor arrecadado com esta habilidade.
# 7. Classe Gerente
Classe derivada de funcionário, e como o nome já explicita responsável por gerenciar a boate e efetuar compras analisar currículos adicionar despesas entre outras. A classe apresenta as respectivas funções.

    GET_COMPRAR
    
Função responsável pela administração de compras de objetos para a boate.
Observação: as funções set de todas as classes são apenas para exibição em tela.
