//   cd .. (até a raiz /)
//   cd var
//   cd www
//   cd html
//   cd sendMail
//   g++ -o processaEmail processaEmail.c $(mysql_config --libs) -L/path/of/curl/lib/libcurl.a -lcurl
//   ./processaEmail                                   - Executar programa
//   chmod +x /var/www/html/sendMail/processaEmail     - Dar Permissão de execução para o agendador
//   vi /etc/crontab                                   - Visualizar Agendador





using namespace std;

#include <string.h>
#include <stdio.h>
#include "/usr/include/mysql/mysql.h"
#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <iomanip> 


const size_t nTotCh1 = 500;
const size_t nTotCh2 = 1000000;

char aEmaToo[nTotCh1];
char aEmaFro[nTotCh1];
char aEmaSub[nTotCh1];
char aEmaBod[nTotCh2];






//------------------------------------ FUNÇÕES ------------------------------------------------
string toString (int a)
{
	string result;
	
	stringstream str;
	str << a;
	str >> result;
	return result;
}

string toString (double a)
{
	stringstream stream;
	stream << fixed << setprecision(0) << a;
	string s = stream.str();
	return s;
}

int toInt (char * a)
{
	int result;
	istringstream strStream(a);
	strStream >> result;
	return result;
}

double toDouble (char * a)
{
	double result;
	istringstream strStream(a);
	strStream >> result;
	return result;
}

void replaceAll( string &s, const string &search, const string &replace ) {
    for( size_t pos = 0; ; pos += replace.length() ) {
        // Locate the substring to replace
        pos = s.find( search, pos );
        if( pos == string::npos ) break;
        // Replace by erasing and inserting
        s.erase( pos, search.length() );
        s.insert( pos, replace );
    }
}

//---------------------------------------------------------------------------------------------





//------------------------------- ENVIAR EMAIL ------------------------------------------------
static char *payload_text[] = {
			"Content-Type: text/html; charset=\"UTF-8\"",
			"To: ",aEmaToo," \r\n",
			"From: ",aEmaFro," \r\n",
			"Subject: ",aEmaSub,"\r\n",
			"Mime-version: 1.0\r\n",
			"<html><head>																			    \
				<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">              \
				</head><body>																			\
				",aEmaBod,"								                                            \
			</body></html>\r\n",
			NULL
	};
 
struct upload_status {
  int lines_read;
};
 
static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
	struct upload_status *upload_ctx = (struct upload_status *)userp;
	const char *data;
 
	if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
		return 0;
	}
	
	data = payload_text[upload_ctx->lines_read];
	
	if(data) {
		size_t len = strlen(data);
		memcpy(ptr, data, len);
		upload_ctx->lines_read++;
	
		return len;
	}
 
	return 0;
}
//---------------------------------------------------------------------------------------------





//------------------------------- ENVIAR EMAIL ------------------------------------------------
main()
{
	try
	{
	
	int nSeqEma;
	int nCodOco;
	int nAbeOco = 0;
	int nSidOco = 0;
	double nDatPrc = 0;
	bool bConPrc = true;
	
	string aAcaOco = "";
	string aQryTmp = "";
	string aConOco = ""; 
	string aDesOco = ""; 
	string aRamOco = "";  										 
	string aLocOco = ""; 								 
	string aSisOco = ""; 
	string aSemOco = ""; 
	string aOpeOco = ""; 
	string aOemOco = ""; 		 
	string aCemOco = ""; 							 
	string aPrbOco = "";
	string aAssOco = "";
	string aSolOco = "";
	string aMsgFro = "";
	string aMsgRep = "";
	string aMsgSub = "";
	string aMsgBod = "";
	string aMsgAlt = "";
	string aRecNom = "";
	string aRecEma = "";
	string aRecToo = "";
	string aRecFro = "";
	string aMsgAux = "";
	
	
	
	
	MYSQL conexao;
	MYSQL_RES *resEma;
	MYSQL_ROW linEma;
	MYSQL_RES *resOco;
	MYSQL_ROW linOco;
	
	
	string aQryEma = " SELECT sequencia,ocorrencia,evento,TO_SECONDS(data) FROM aviso_email ORDER BY sequencia;";
	
	string aQryOco = "	SELECT oco.numero as oconum, oco.contato as ococon, oco.descricao as ocodes, oco.telefone as ocoram, \
							   abe.nome as ocoapo,																			 \
							   loc.local  as locdes,																		 \
							   are.sistema as aredes,are.sis_id as arecod,							                         \
							   ope.nome as openom,														                     \
							   prb.problema as prbdes																		 \
						  FROM ocorrencias as oco																			 \
								LEFT JOIN localizacao as loc on loc.loc_id = oco.local										 \
								LEFT JOIN sistemas as are on are.sis_id = oco.sistema										 \
								LEFT JOIN usuarios as ope on ope.user_id = oco.operador										 \
								LEFT JOIN usuarios as abe on abe.user_id = oco.aberto_por									 \
								LEFT JOIN problemas as prb on prb.prob_id = oco.problema									 \
						 WHERE oco.numero = ";	
	
	string aQryMsg = " SELECT msg_fromname,msg_replyto,msg_subject,msg_body,msg_altbody FROM msgconfig WHERE msg_event = 'opeOcorrencias%aAcaOco%'";
	
	string aQryAss = " SELECT assentamento FROM assentamentos WHERE ocorrencia = %nCodOco% AND TO_SECONDS(data) >= %nSecMen%  AND TO_SECONDS(data) <= %nSecMai%";
	
	string aQrySol = " SELECT solucao FROM solucoes WHERE numero = %nCodOco% AND TO_SECONDS(data) >= %nSecMen% ORDER BY data DESC";
	
	string aQryRec = "SELECT DISTINCT nome,email FROM(																		\
							SELECT usu.nome AS nome,usu.email AS email 														\
							FROM usuarios AS usu																			\
							WHERE usu.user_admin = 1 AND usu.AREA=%nSidOco% 												\
							UNION																							\
							SELECT usu.nome AS nome,usu.email AS email														\
							FROM usuarios AS usu, usuarios_areas AS uar 													\
							WHERE uar.uarea_uid = usu.user_id AND uar.uarea_admin = 1 AND uar.uarea_sid=%nSidOco% 			\
							UNION																							\
							SELECT ope.nome AS nome,ope.email AS email 														\
							FROM ocorrencias as oco,usuarios as ope 														\
							WHERE ope.user_id = oco.operador AND oco.numero = %nCodOco%										\
							UNION																							\
							SELECT usu.nome AS nome,usu.email AS email 														\
							FROM ocorrencias as oco, usuarios as usu														\
							WHERE usu.nome = oco.contato AND oco.numero = %nCodOco%											\
						) AS tbl";
	
	string aQryDel = "DELETE FROM aviso_email WHERE sequencia = %sequencia%";
	
	
	
	mysql_init(&conexao);
	mysql_options(&conexao, MYSQL_SET_CHARSET_NAME, "utf8"); 
	mysql_options(&conexao, MYSQL_INIT_COMMAND, "SET NAMES utf8"); 
	
	
						
	
	if ( mysql_real_connect(&conexao, "localhost", "root", "Cotrirosa14", "chamado", 0, 0, 0) ) {
		if (mysql_query(&conexao,aQryEma.c_str()))
			printf("Erro: %s\n",mysql_error(&conexao));
		else{ 
			resEma = mysql_store_result(&conexao);
			if (resEma){
				while ((linEma=mysql_fetch_row(resEma)) != NULL){
					nSeqEma = toInt(linEma[0]); // sequencia
					nCodOco = toInt(linEma[1]); // ocorrencia
					aAcaOco = linEma[2];        // evento
					nDatPrc = toDouble(linEma[3]); // evento
					
					aMsgAux = "Sequencia: "+ toString(nSeqEma) + "; Ocorrência: " + toString(nCodOco) + " | ";
					printf(aMsgAux.c_str());
					nAbeOco = 0;
					nSidOco = 0; 
					aQryTmp = "";
					aConOco = ""; 
					aDesOco = ""; 
					aRamOco = "";  										 
					aLocOco = ""; 								 
					aSisOco = ""; 
					aSemOco = ""; 
					aOpeOco = ""; 
					aOemOco = ""; 		 
					aCemOco = ""; 							 
					aPrbOco = "";
					aAssOco = "";
					aSolOco = "";
					aMsgFro = "";
					aMsgRep = "";
					aMsgSub = "";
					aMsgBod = "";
					aMsgAlt = "";
					aRecNom = "";
					aRecEma = "";
					aRecToo = "";
					aRecFro = "";
					
					
					
					// Não remover essas declarações daqui, a cada chamado precisa criar as declarações
					CURL *curl;
					CURLcode res = CURLE_OK;
					struct curl_slist *recipients = NULL;
					struct curl_slist *headers = NULL;
					struct upload_status upload_ctx;

					upload_ctx.lines_read = 0;
										
					aQryTmp = aQryOco + toString(nCodOco) + ";";
					
					bConPrc = true;
					//------------------------ ACESSAR OCORRÊNCIA --------------------------------
					if (bConPrc){
						if (mysql_query(&conexao,aQryTmp.c_str())){
							printf("Erro: %s\n",mysql_error(&conexao));
							bConPrc = false;
						} else{ 
							resOco = mysql_store_result(&conexao);
							
							
							if (resOco){
								while ((linOco=mysql_fetch_row(resOco)) != NULL){
									//nCodOco = toInt(linOco[0]);        //oco.numero as oconum        - '%numero%
									aConOco = linOco[1];                 //oco.contato as ococon       - '%usuario%' , '%contato%'
									aDesOco = linOco[2];                 //oco.descricao as ocodes     - '%descricao%'
									aRamOco = linOco[3];                 //oco.telefone as ocoram      - '%ramal%' 
									nAbeOco = toInt(linOco[4]);          //abe.nome as ocoapo          - '%aberto_por%'																			 
									aLocOco = linOco[5];                 //loc.local  as locdes        - '%setor%'																		 
									aSisOco = linOco[6];                 //are.sistema as aredes       - '%area%'
									nSidOco = toInt(linOco[7]);          //are.sis_id as arecod        - 							 
									aOpeOco = linOco[8];                 //ope.nome as openom          - '%operador%' , '%editor%' , '%foward%'														 
									aPrbOco = linOco[9];                 //prb.problema as prbdes      - '%problema%'
									
								}
							} else {
								bConPrc = false;
							}	
						}
					}		



					//------------------------ Assentamento --------------------------------
					if (bConPrc){
						aQryTmp = aQryAss;
						replaceAll(aQryTmp,"%nCodOco%", toString(nCodOco));
						replaceAll(aQryTmp,"%nSecMen%", toString(nDatPrc - 20));
						replaceAll(aQryTmp,"%nSecMai%", toString(nDatPrc + 20));
						if (mysql_query(&conexao,aQryTmp.c_str())){
							printf("Erro: %s\n",mysql_error(&conexao));
							bConPrc = false;
						} else{ 
							resOco = mysql_store_result(&conexao);
							
							if (resOco){ 
								if ((linOco=mysql_fetch_row(resOco)) != NULL)
									aAssOco= linOco[0];
							} else {
								bConPrc = false;
							}
						}
					}
					
					
					//------------------------ Solução --------------------------------
					if (bConPrc){
						aQryTmp = aQrySol;
						replaceAll(aQryTmp,"%nCodOco%", toString(nCodOco));
						replaceAll(aQryTmp,"%nSecMen%", toString(nDatPrc - 20));
						replaceAll(aQryTmp,"%nSecMai%", toString(nDatPrc + 20));
						if (mysql_query(&conexao,aQryTmp.c_str())){
							printf("Erro: %s\n",mysql_error(&conexao));
							bConPrc = false;
						} else{ 
							resOco = mysql_store_result(&conexao);
							
							if (resOco){ 
								if ((linOco=mysql_fetch_row(resOco)) != NULL)
									aSolOco= linOco[0];
							} else {
								bConPrc = false;
							}
						}
					}					
										
					//------------------------ MODELO DE EMAIL --------------------------------
					if (bConPrc){
						aQryTmp = aQryMsg;
						replaceAll(aQryTmp,"%aAcaOco%", aAcaOco);
						if (mysql_query(&conexao,aQryTmp.c_str())){
							printf("Erro: %s\n",mysql_error(&conexao));
							bConPrc = false;
						} else{ 
							resOco = mysql_store_result(&conexao);
							
							if (resOco){								
								while ((linOco=mysql_fetch_row(resOco)) != NULL){
									aMsgFro = linOco[0];                 //msg_fromname   
									aMsgRep = linOco[1];                 //msg_replyto
									aMsgSub = linOco[2];                 //msg_subject
									aMsgBod = linOco[3];                 //msg_body  
									aMsgAlt = linOco[4];                 //msg_altbody  
									
									replaceAll(aMsgFro,"%nCodOco%",toString(nCodOco));
									replaceAll(aMsgFro,"%aConOco%",aConOco);
									replaceAll(aMsgFro,"%aDesOco%",aDesOco);
									replaceAll(aMsgFro,"%aRamOco%",aRamOco);
									replaceAll(aMsgFro,"%nAbeOco%",toString(nAbeOco));
									replaceAll(aMsgFro,"%aLocOco%",aLocOco);
									replaceAll(aMsgFro,"%aSisOco%",aSisOco);
									replaceAll(aMsgFro,"%nSidOco%",toString(nSidOco));
									replaceAll(aMsgFro,"%aOpeOco%",aOpeOco);
									replaceAll(aMsgFro,"%aPrbOco%",aPrbOco);
									replaceAll(aMsgFro,"%aAssOco%",aAssOco);
									replaceAll(aMsgFro,"%aSolOco%",aSolOco);
									
									replaceAll(aMsgRep,"%nCodOco%",toString(nCodOco));
									replaceAll(aMsgRep,"%aConOco%",aConOco);
									replaceAll(aMsgRep,"%aDesOco%",aDesOco);
									replaceAll(aMsgRep,"%aRamOco%",aRamOco);
									replaceAll(aMsgRep,"%nAbeOco%",toString(nAbeOco));
									replaceAll(aMsgRep,"%aLocOco%",aLocOco);
									replaceAll(aMsgRep,"%aSisOco%",aSisOco);
									replaceAll(aMsgRep,"%nSidOco%",toString(nSidOco));
									replaceAll(aMsgRep,"%aOpeOco%",aOpeOco);
									replaceAll(aMsgRep,"%aPrbOco%",aPrbOco);
									replaceAll(aMsgRep,"%aAssOco%",aAssOco);
									replaceAll(aMsgRep,"%aSolOco%",aSolOco);
									
									replaceAll(aMsgSub,"%nCodOco%",toString(nCodOco));
									replaceAll(aMsgSub,"%aConOco%",aConOco);
									replaceAll(aMsgSub,"%aDesOco%",aDesOco);
									replaceAll(aMsgSub,"%aRamOco%",aRamOco);
									replaceAll(aMsgSub,"%nAbeOco%",toString(nAbeOco));
									replaceAll(aMsgSub,"%aLocOco%",aLocOco);
									replaceAll(aMsgSub,"%aSisOco%",aSisOco);
									replaceAll(aMsgSub,"%nSidOco%",toString(nSidOco));
									replaceAll(aMsgSub,"%aOpeOco%",aOpeOco);
									replaceAll(aMsgSub,"%aPrbOco%",aPrbOco);
									replaceAll(aMsgSub,"%aAssOco%",aAssOco);
									replaceAll(aMsgSub,"%aSolOco%",aSolOco);
									
									replaceAll(aMsgBod,"%nCodOco%",toString(nCodOco));
									replaceAll(aMsgBod,"%aConOco%",aConOco);
									replaceAll(aMsgBod,"%aDesOco%",aDesOco);
									replaceAll(aMsgBod,"%aRamOco%",aRamOco);
									replaceAll(aMsgBod,"%nAbeOco%",toString(nAbeOco));
									replaceAll(aMsgBod,"%aLocOco%",aLocOco);
									replaceAll(aMsgBod,"%aSisOco%",aSisOco);
									replaceAll(aMsgBod,"%nSidOco%",toString(nSidOco));
									replaceAll(aMsgBod,"%aOpeOco%",aOpeOco);
									replaceAll(aMsgBod,"%aPrbOco%",aPrbOco);
									replaceAll(aMsgBod,"%aAssOco%",aAssOco);
									replaceAll(aMsgBod,"%aSolOco%",aSolOco);
									
									replaceAll(aMsgAlt,"%nCodOco%",toString(nCodOco));
									replaceAll(aMsgAlt,"%aConOco%",aConOco);
									replaceAll(aMsgAlt,"%aDesOco%",aDesOco);
									replaceAll(aMsgAlt,"%aRamOco%",aRamOco);
									replaceAll(aMsgAlt,"%nAbeOco%",toString(nAbeOco));
									replaceAll(aMsgAlt,"%aLocOco%",aLocOco);
									replaceAll(aMsgAlt,"%aSisOco%",aSisOco);
									replaceAll(aMsgAlt,"%nSidOco%",toString(nSidOco));
									replaceAll(aMsgAlt,"%aOpeOco%",aOpeOco);
									replaceAll(aMsgAlt,"%aPrbOco%",aPrbOco);
									replaceAll(aMsgAlt,"%aAssOco%",aAssOco);
									replaceAll(aMsgAlt,"%aSolOco%",aSolOco);
									
									
									
								}
								
							} else {
								bConPrc = false;
							}
						}
					}
					
					//------------------------ EMAIL's --------------------------------
					curl = curl_easy_init();
					if(bConPrc && curl) {//995 465
						curl_easy_setopt(curl, CURLOPT_URL, "smtps://mail.cotrirosa.com.br:465");
						curl_easy_setopt(curl, CURLOPT_USERNAME, "naoresponda@cotrirosa.com.br");
						curl_easy_setopt(curl, CURLOPT_PASSWORD, "nop.cotri.1968");
						curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "<naoresponda@cotrirosa.com.br>");
						curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
						
						
						aRecFro = "Help Desk <naoresponda@cotrirosa.com.br>";	
						
						
						
						aQryTmp = aQryRec;
						replaceAll(aQryTmp,"%nCodOco%", toString(nCodOco));
						replaceAll(aQryTmp,"%nSidOco%", toString(nSidOco));
						if (mysql_query(&conexao,aQryTmp.c_str())){
							printf("Erro: %s\n",mysql_error(&conexao));
							bConPrc = false;
						} else{ 
							resOco = mysql_store_result(&conexao);
							
							if (resOco){	
								bConPrc = false;
								while ((linOco=mysql_fetch_row(resOco)) != NULL){
									aRecNom = linOco[0];                 //nome   
									aRecEma = linOco[1];                 //email								
									if ((aRecEma != "") && (aRecEma != " ")){
										aRecEma = "<" + aRecEma + ">";
										recipients = curl_slist_append(recipients, aRecEma.c_str());
										aRecToo = aRecToo + aRecNom + " " + aRecEma + ";";
										
										bConPrc = true;
									}
								}
							} else {
								bConPrc = false;
							}
						}
						
						
						/* Teste local de envio de Email 
						aRecToo = "Analista <analista@cotrirosa.com.br>;Leandro Jorge Junges <leandrojunges@yahoo.com.br>;";
						//curl_slist_free_all(recipients);
						recipients = curl_slist_append(recipients, "<analista@cotrirosa.com.br>");
						recipients = curl_slist_append(recipients, "<leandroj888@hotmail.com>");
						recipients = curl_slist_append(recipients, "<leandrojunges@yahoo.com.br>");
						/* Teste local de envio de Email */
					}
					
					
					
					
					if (bConPrc){
						curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
						
						char aAuxToo[nTotCh1];
						char aAuxFro[nTotCh1];
						char aAuxSub[nTotCh1];
						char aAuxBod[nTotCh2];
						

						memset(aAuxToo, '\0', sizeof(aAuxToo));
						memset(aAuxFro, '\0', sizeof(aAuxFro));
						memset(aAuxSub, '\0', sizeof(aAuxSub));
						memset(aAuxBod, '\0', sizeof(aAuxBod));

						aRecToo.copy(aAuxToo, nTotCh1);
						aRecFro.copy(aAuxFro, nTotCh1);
						aMsgSub.copy(aAuxSub, nTotCh1);
						aMsgBod.copy(aAuxBod, nTotCh2);

						memcpy(aEmaToo, aAuxToo, nTotCh1);
						memcpy(aEmaFro, aAuxFro, nTotCh1);
						memcpy(aEmaSub, aAuxSub, nTotCh1);
						memcpy(aEmaBod, aAuxBod, nTotCh2);
						

						if(curl) {
							curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
							curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
							 
							res = curl_easy_perform(curl);
							if(res != CURLE_OK)
								bConPrc = false;							
						}
					}
					
					if(curl) {
						curl_easy_cleanup(curl);
						curl_slist_free_all(recipients);	
					}
					
					if (bConPrc){
						aQryTmp = aQryDel;
						replaceAll(aQryTmp,"%sequencia%", toString(nSeqEma));
						if (mysql_query(&conexao,aQryTmp.c_str())){
							printf("Erro: %s\n",mysql_error(&conexao));
							bConPrc = false;
						}
					}
					
					if (bConPrc)
						printf(" Processo concluido \n");
					else
						printf(" Erro no Processo \n");
				}
			}
		}
	} else {
		printf("Falha de conexao\n");
		printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	}
	
	
	} catch (exception& e){
		cout << e.what() << '\n';
	}

}
