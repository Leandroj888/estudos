<?php
/** 
 * Comentário de cabeçalho 01dados.php
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
 * @criação     6 de jun de 2017 - 09:45:23
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
        $d = isset($_GET["ds"])?$_GET["ds"]:0; 
        
        switch($d){
            case 2:
            case 3: 
            case 4: 
            case 5: 
            case 6: 
                echo "Levanta e vai estudar! :)"; 
                break;
            case 7: 
            case 8: 
                echo "Descanse, pequeno gaganhoto! ;)";
                break;
            default:
                echo "Dia da Semana Inválido.";
        }
        
	?>
	<br/> <a href="javascript:history.go(-1)" class="botao">Voltar</a>
	</div>
    </body>
</html>