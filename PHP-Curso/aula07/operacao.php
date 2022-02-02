<?php
/**
 * Comentário de cabeçalho operacao.php
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
 * @criação     5 de jun de 2017 - 17:50:56
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
        $n1 = $_GET["a"];
        $n2 = $_GET["b"];
        $tipo = $_GET["op"];
        
        echo "Os valores passados foram $n1 e $n2 <br/>";
        
        $r = $tipo=="s"?$n1+$n2:$n1*$n2;
        
        echo "O resultado foi $r <br/>";
      
	?>
	</div>
    </body>
</html>