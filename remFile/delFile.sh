#chmod +x /var/www/html/remFile/remfile.sh
#
#
#!/bin/bash
#
PASTA_DESTINO= /var/www/html/chamado/uploads
#
TEMPO_LIMITE=9
#
clear;
echo "Executando `basename $0`.";
find $PASTA_DESTINO -name 'tmp*' -type d;
#find $PASTA_DESTINO -name 'tmp*' -type d -mtime +$TEMPO_LIMITE -exec rm -rf {} \;

