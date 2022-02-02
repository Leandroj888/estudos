<?php
/**
 * Comentário de cabeçalho tipos.php
 * Definir aqui a função designada a esse arquivo
 *
 *
 * @autor   	Leandro Jorge Junges <analista@cotrirosa.com.br>
 * @versão  	0.1
 * @licença 	Todos Direitos Reservados a Cotrirosa Copyright © 2017
 * @empresa 	Cooperativa Tritícola Santa Rosa Ltda - Cotrirosa
 * @setor   	Departamento de Tecnologia da Informação
 * @acesso  	público
 * @codificação UTF-8
 * @linguagem   PHP - PT/BR
 * @criação     5 de jun de 2017 - 10:14:16
 * @local       \
 */
?>

<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8"/>
  <link rel="stylesheet" href="../_css/estilo.css"/>
  <title></title>
</head>
<body>
<div>
    <?php
       $nome = "Maria";
       $idade = 18;
       echo $nome." tem ".$idade." anos! </br>";
       echo "$nome tem $idade anos!";
       echo '$nome tem $idade anos!'; /* Sintax errado */
    ?>
</div>
</body>
</html>