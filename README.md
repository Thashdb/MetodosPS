<h2>Laboratório 1</h2>

<ol>
<li> Criem um diagrama de casos de uso para o sistema de gerenciamento de usuários do seu projeto. Considere pelo menos dois tipos de atores. </li>

<li> Elaborem um diagrama de classe de análise (Fronteira, Entidade e Controle)</li>

<li>Criem a divisão de pacotes/pastas para o seu sistema </li>

<li>Implementem a ADIÇÃO DE USUÁRIOS </li>

<li>Armazenem os usuários numa coleção e implemente a persistencia numa coleção utilizando memória RAM </li>

<li>Implementem a funcionalidade de LISTAR TODOS OS USUÁRIOS </li>

</ol>

<h2>Laboratório 2</h2>

<h3>Projeto: Tratamento de erros</h3>

<ol>
<li> Atualizar o diagrama de classes do laboratório iniciado na aula anterior, incluindo as features abaixo (validação dos campos utilizando exceções e uso de 2 mecanismos de persistência). </li>
<li> Para adição de usuário, implemente as validações de campos utilizando tratamento de erros seguindo as regras abaixo: 
    <ul>
        <li>Login:
            <ul>
                <li>máximo 12 caracteres</li>
                <li>não pode ser vazio</li>
                <li>não pode ter números</li>
            </ul>
        </li>
        <li>Senha:
            <ul>
                <li>Seguir as regras das políticas do AWS IAM: <a href="https://docs.aws.amazon.com/pt_br/IAM/latest/UserGuide/id_credentials_passwords_account-policy.html">AWS IAM Password Policy</a></li>
            </ul>
        </li>
    </ul>
</li>
<li> Permitir o armazenamento de usuários numa coleção também utilizando arquivo binário ou BD (pode ser chaveado com o armazenamento em RAM no início da execução). Implementar tratamento de exceções (por exemplo, IOException ou SQLException). </li>
</ol>

<h2>Laboratório 3</h2>

<h3>Padrões 1</h3>

<ol>
<li> Criar um diagrama de classe atualizado com o projeto contemplando o item 2 abaixo. </li>
<li> Implementar o cadastro (CRUD) de uma nova entidade do seu projeto (preferencialmente que tenha relacionamento com Usuário ou com outra Entidade). </li>
<li> Criar uma fachada única (usando Singleton e Facade) para os Gerentes (Controller). Nessa classe (<code>FacadeSingletonController</code>) deve existir um método que retorna a quantidade de entidades cadastradas no sistema. </li>
</ol>

<h2>Laboratório 4</h2>

<h3>Padrões 2 (Projeto 2)</h3>

<ol>
<li> Estudar o padrão DAO e refazer o diagrama de classes do projeto para separar a comunicação entre as camadas <code>business</code> e de persistência (<code>infra</code>). </li>
<li> Implementar o DAO ou o uso de Abstract Factory ou Factory Method para separar a comunicação entre as camadas <code>business</code> e de persistência (<code>infra</code>). </li>
<li> De acordo com o padrão Adapter, identificar e implementar um cenário de uso no projeto (sugestão: usar lib de log). </li>
<li> Na camada <code>business</code>, implementar, utilizando Template Method, a geração de mais um tipo de relatórios (por exemplo, HTML e PDF). Os relatórios devem gerar estatísticas de acesso dos usuários no sistema. </li>
<li> Atualizar o diagrama de classe com identificação dos padrões de projeto utilizados até o momento no documento de requisitos/projeto. </li>
</ol>

<h2>Projeto Final</h2>

<ol>
<li> Terminar os padrões (tarefas) já passados. </li>
<li> Implementar mais 2 (dois) padrões de projeto que ainda não foram pedidos, de acordo com o documento de requisitos. </li>
<li> Atualizar o diagrama de classes final usando os modelos C4, identificando por cores cada padrão de projeto implementado. </li>
<li> Para cada padrão, descrever um texto com o nome do padrão, a lista de classes e o objetivo de uso do padrão no projeto. </li>
</ol>