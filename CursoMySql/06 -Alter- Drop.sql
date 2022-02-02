USE cadastro;

ALTER TABLE pessoas ADD COLUMN profissao varchar(10);

DESC pessoas;

SELECT * FROM pessoas;

ALTER TABLE pessoas DROP COLUMN profissao;

DESC pessoas;

ALTER TABLE pessoas ADD COLUMN profissao varchar(10) AFTER nome;

DESC pessoas;

ALTER TABLE pessoas ADD COLUMN codid INT FIRST;

DESC pessoas;

ALTER TABLE pessoas DROP COLUMN codid;

DESC pessoas;

ALTER TABLE pessoas MODIFY COLUMN profissao VARCHAR(20) NOT NULL DEFAULT '';

DESC pessoas;

ALTER TABLE pessoas CHANGE COLUMN profissao prof VARCHAR(20);

DESC pessoas;

ALTER TABLE pessoas RENAME TO gafanhotos;

DESC gafanhotos;

CREATE TABLE IF NOT EXISTS cursos(
	nome VARCHAR(30) NOT NULL UNIQUE,
    descricao TEXT,
    carga INT UNSIGNED,
    totaulas INT,
    ano YEAR DEFAULT '2016'
)DEFAULT CHARSET utf8;

DESC cursos;

ALTER TABLE cursos ADD COLUMN idcurso INT FIRST;

DESC cursos;

ALTER TABLE cursos ADD PRIMARY KEY(idcurso);

DESC cursos;

CREATE TABLE IF NOT EXISTS teste(
	id INT,
	nome VARCHAR(10),
	idade INT
);

INSERT INTO  teste VALUE ('1','Pedro','22'),
						 ('2','Maria','12'),
                         ('3','Maricota','77');

DROP TABLE IF EXISTS teste;

