<?php
/** 
 * Comentário de cabeçalho funcoesaritimeticas.php
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
 * @criação     5 de jun de 2017 - 14:02:34
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
		<style type="text/css">
		  h2{
		      font: 15pt Arial;
		      color: #171559;
		      font-weight: bold;
		  }
		</style>
	</head>
    <body>
    <div>
    <?php
        $v1 = $_GET["x"];
        $v2 = $_GET["y"];
        
        echo "<h2>Valores Recebidos: $v1 e $v2</h2>";
        echo "O valor absoluto de $v2 e " . abs($v2);
        echo "<br/> O valor de $v1 <sup>$v2</sup> e " . pow($v1,$v2);
        echo "<br/> A Raiz de $v1 e " . sqrt($v1);
        echo "<br/> O valor arredondado de $v1 e " . round($v1);
        echo "<br/> O valor arredondado pra cima de $v1 e " . ceil($v1); 
        echo "<br/> O valor arredondado pra baixo de $v1 e " . floor($v1); 
        echo "<br/> O valor inteiro de $v1 e " . intval($v1); 
        echo "<br/> O valor de $v1 em moeda R$" . number_format($v1,2,",","."); 
	?>
	</div>
    </body>
</html>