#chmod +x /var/www/html/remFile/remFile.sh



#!/bin/bash

PASTA_DESTINO=/var/www/html/chamado/uploads

TEMPO_LIMITE=1

echo "Limpeza de arquivos temporário da pasta '$PASTA_DESTINO' com mais de $TEMPO_LIMITE dia(s).";
find $PASTA_DESTINO -name 'tmp*' -type d -mtime +$TEMPO_LIMITE -exec rm -rf {} \;  
