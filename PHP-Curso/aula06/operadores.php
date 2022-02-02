<?php
/** 
 * Comentário de cabeçalho operadores.php
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
 * @criação     5 de jun de 2017 - 14:36:54
 * @local       \
 */
?>

<!DOCTYPE HTML>
<html lang="pt-br">
	<head>
		<meta http-equiv="Content-Language" content="pt-br">
		<meta charset="utf-8">
		<title>Primeiro Texto</title>
		<link rel="icon" href="img/icopag.ico" type="image/x-icon" />
		<link rel="shortcut icon" href="img/icopag.ico" type="image/x-icon" />
  		<link rel="stylesheet" href="../_css/estilo.css"/>
	</head>
    <body>
    <div>
    <?php
        $preco = $_GET["p"];
        echo "O preço do produto e R$". number_format($preco,2,",",".");
        //$preco = $preco + ($preco*10/100);
        $preco -= $preco*10/100;
        echo "</br>e o novo preço com 10% de desconto e R$". number_format($preco,2,",",".");
	?>
	</div>
    </body>
</html>