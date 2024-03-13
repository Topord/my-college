# 开发框架路径
PUBINCL = -I/project/public

# 开发框架CPP 文件名
PUBCPP = /project/public/_public.cpp

# mysql头文件存放路径
MYSQLINCL = -I/usr/include/mysql  -I/project/public/db/mysql

# mysql库文件保存路径
MYSQLLIB = -L/usr/lib64/mysql

# mysql链接库
MYSQLLIBS = -lmysqlclient

# 开发框架mysql的cpp文件名，这里直接包含进来，没有采用链接库，是为了方便调试。
MYSQLCPP = /project/public/db/mysql/_mysql.cpp

# oracle头文件路径
ORAINCL = -I$(ORACLE_HOME)/rdbms/public -I/project/public/db/oracle

# oracle库文件路径
ORALIB =  -L$(ORACLE_HOME)/lib -L.

# oracle的oci库
ORALIBS = -lclntsh

# 开发框架oracle的cpp文件名，这里直接包含进来，没有采用链接库，是为了方便调试。
ORACPP = /project/public/db/oracle/_ooci.cpp

# 编译参数
CFLAS = -g

all:procctl checkproc gzipfiles deletefiles ftpgetfiles ftpgetfiles2 ftpgetfiles3 ftpputfiles\
 tcpputfiles fileserver tcpgetfiles myfileserver execsql dminingmysql xmltodb syncupdate deletetable\
 migratetable syncincrement xmltodb_oracle syncupdate_oracle deletetable_oracle migratetable_oracle\
 syncincrement_oracle dminingoracle
 
procctl:procctl.cpp
	g++ -o procctl procctl.cpp
	cp procctl ../bin/.

checkproc:checkproc.cpp
	g++ $(CFLAGS) -o checkproc checkproc.cpp $(PUBINCL) $(PUBCPP) -lm -lc
	cp checkproc ../bin/.

gzipfiles:gzipfiles.cpp
	g++ $(CFLAGS) -o gzipfiles gzipfiles.cpp $(PUBINCL) $(PUBCPP) -lm -lc
	cp gzipfiles ../bin/.

deletefiles:deletefiles.cpp
	g++ $(CFLAGS) -o deletefiles deletefiles.cpp $(PUBINCL) $(PUBCPP) -lm -lc
	cp deletefiles ../bin/.

ftpgetfiles:ftpgetfiles.cpp
	g++ $(CFLAGS) -g -o ftpgetfiles ftpgetfiles.cpp $(PUBINCL) $(PUBCPP) /project/public/libftp.a /project/public/_ftp.cpp -lm -lc
	cp ftpgetfiles ../bin/.

ftpgetfiles2:ftpgetfiles2.cpp 
	g++ $(CFLAGS) -g -o ftpgetfiles2 ftpgetfiles2.cpp $(PUBINCL) $(PUBCPP) /project/public/libftp.a /project/public/_ftp.cpp -lm -lc
	cp ftpgetfiles2 ../bin/.

ftpgetfiles3:ftpgetfiles3.cpp
	g++ $(CFLAGS) -g -o ftpgetfiles3 ftpgetfiles3.cpp $(PUBINCL) $(PUBCPP) /project/public/libftp.a /project/public/_ftp.cpp -lm -lc
	cp ftpgetfiles3 ../bin/.

ftpputfiles:ftpputfiles.cpp
	g++ $(CFLAGS) -g -o ftpputfiles ftpputfiles.cpp $(PUBINCL) $(PUBCPP) /project/public/libftp.a /project/public/_ftp.cpp -lm -lc
	cp ftpputfiles ../bin/.

tcpputfiles:tcpputfiles.cpp
	g++ $(CFLAGS) -o tcpputfiles tcpputfiles.cpp $(PUBINCL) $(PUBCPP) -lm -lc
	cp tcpputfiles ../bin/.

fileserver:fileserver.cpp
	g++ $(CFLAGS) -o fileserver fileserver.cpp $(PUBINCL) $(PUBCPP) -lm -lc
	cp fileserver ../bin/.

tcpgetfiles:tcpgetfiles
	g++ $(CFLAGS) -o tcpgetfiles tcpgetfiles.cpp $(PUBINCL) $(PUBCPP) -lm -lc
	cp tcpgetfiles ../bin/.

myfileserver:myfileserver.cpp
	g++ $(CFLAGS) -o myfileserver myfileserver.cpp $(PUBINCL) $(PUBCPP) -lm -lc
	cp myfileserver ../bin/.

execsql:execsql.cpp
	g++ $(CFLAGS) -o execsql execsql.cpp $(PUBINCL) $(PUBCPP) $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS) $(MYSQLCPP) -lm -lc
	cp execsql ../bin/.

dminingmysql:dminingmysql.cpp
	g++ $(CFLAGS) -o dminingmysql dminingmysql.cpp $(PUBINCL) $(PUBCPP) $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS) $(MYSQLCPP) -lm -lc
	cp dminingmysql ../bin/.

xmltodb:xmltodb.cpp _tools.h _tools.cpp
	g++ $(CFLAGS) -o xmltodb xmltodb.cpp _tools.cpp $(PUBINCL) $(PUBCPP) $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS) $(MYSQLCPP) -lm -lc
	cp xmltodb ../bin/.

syncupdate:syncupdate.cpp _tools.h _tools.cpp
	g++ $(CFLAGS) -o syncupdate syncupdate.cpp _tools.cpp $(PUBINCL) $(PUBCPP) $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS) $(MYSQLCPP) -lm -lc
	cp syncupdate ../bin/.

syncincrement:syncincrement.cpp _tools.h _tools.cpp
	g++ $(CFLAGS) -o syncincrement syncincrement.cpp _tools.cpp $(PUBINCL) $(PUBCPP) $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS) $(MYSQLCPP) -lm -lc
	cp syncincrement ../bin/.


deletetable:deletetable.cpp _tools.h _tools.cpp
	g++ $(CFLAGS) -o deletetable deletetable.cpp _tools.cpp $(PUBINCL) $(PUBCPP) $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS) $(MYSQLCPP) -lm -lc
	cp deletetable ../bin/.

migratetable:migratetable.cpp _tools.h _tools.cpp
	g++ $(CFLAGS) -o migratetable migratetable.cpp _tools.cpp $(PUBINCL) $(PUBCPP) $(MYSQLINCL) $(MYSQLLIB) $(MYSQLLIBS) $(MYSQLCPP) -lm -lc
	cp migratetable ../bin/.

xmltodb_oracle:xmltodb_oracle.cpp _tools_oracle.h _tools_oracle.cpp
	g++ $(CFLAGS) -o xmltodb_oracle xmltodb_oracle.cpp _tools_oracle.cpp $(PUBINCL) $(PUBCPP) $(ORAINCL) $(ORALIB) $(ORALIBS) $(ORACPP) -lm -lc
	cp xmltodb_oracle ../bin/.

deletetable_oracle:deletetable_oracle.cpp 
	g++ $(CFLAGS) -o deletetable_oracle deletetable_oracle.cpp $(PUBINCL) $(PUBCPP) $(ORAINCL) $(ORALIB) $(ORALIBS) $(ORACPP) -lm -lc
	cp deletetable_oracle ../bin/.

dminingoracle:dminingoracle.cpp 
	g++ $(CFLAGS) -o dminingoracle dminingoracle.cpp $(PUBINCL) $(PUBCPP) $(ORAINCL) $(ORALIB) $(ORALIBS) $(ORACPP) -lm -lc
	cp dminingoracle ../bin/.

migratetable_oracle:migratetable_oracle.cpp _tools_oracle.h _tools_oracle.cpp
	g++ $(CFLAGS) -o migratetable_oracle migratetable_oracle.cpp _tools_oracle.cpp $(PUBINCL) $(PUBCPP) $(ORAINCL) $(ORALIB) $(ORALIBS) $(ORACPP) -lm -lc
	cp migratetable_oracle ../bin/.

syncupdate_oracle:syncupdate_oracle.cpp _tools_oracle.h _tools_oracle.cpp
	g++ $(CFLAGS) -o syncupdate_oracle syncupdate_oracle.cpp _tools_oracle.cpp $(PUBINCL) $(PUBCPP) $(ORAINCL) $(ORALIB) $(ORALIBS) $(ORACPP) -lm -lc
	cp syncupdate_oracle ../bin/.

syncincrement_oracle:syncincrement_oracle.cpp _tools_oracle.h _tools_oracle.cpp
	g++ $(CFLAGS) -o syncincrement_oracle syncincrement_oracle.cpp _tools_oracle.cpp $(PUBINCL) $(PUBCPP) $(ORAINCL) $(ORALIB) $(ORALIBS) $(ORACPP) -lm -lc
	cp syncincrement_oracle ../bin/.

clean:
	rm -f procctl checkproc gzipfiles deletefiles ftpgetfiles ftpgetfile2 ftpgetfiles3 ftpputfiles tcpputfiles fileserver  myfileserver
	rm -f tcpgetfiles execsql dminingmysql xmltodb syncupdate syncincrement deletetable migratetable 
	rm -f xmltodb_oracle deletetable_oracle dminingoracle migratetable_oracle syncupdate_oracle syncincrement_oracle
