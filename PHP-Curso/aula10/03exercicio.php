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
        $e = isset($_GET["est"])?$_GET["est"]:0;
        switch ($e){
            case "RS":
            case "SC":
            case "PR":
                $r = "Sul";
                break;
            case "SP":
            case "RJ":
            case "MG":
            case "ES":
                $r = "Sudeste";
                break;
            case "MT":
            case "MS":
            case "GO":
            case "DF":
                $r = "Centro-Oeste";
                break;
            case "RN":
            case "MA":
            case "PI":
            case "PB":
            case "PE":
            case "AL":
            case "SE":
            case "CE":
            case "BA":
                $r = "Nordeste";
                break;
            case "AM":
            case "AC":
            case "AP":
            case "TO":
            case "PA":
            case "RO":
            case "RR":
                $r = "Norte";
                break;
        }
        
        echo "Você Mora na <span class='foco'>Região $r </span>"
	?>
	<br/> <a href="javascript:history.go(-1)" class="botao">Voltar</a>
	</div>
    </body>
</html>