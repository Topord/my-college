drop table T_ZHOBOTCODE cascade constraints;

/*==============================================================*/
/* Table: T_ZHOBOTCODE                                          */
/*==============================================================*/
drop    sequence SEQ_ZHOBTCODE;
create  sequence SEQ_ZHOBTCODE increment by 1 minvalue 1 nocycle;
create table T_ZHOBOTCODE 
(
    obtid               varchar2 (10 )         not null,
    ciytname            varchar2 (30 )         not null,
    provname            varchar2 (10 )         not null,
    lat                 number (8 )            not null,
    lon                 number (8 )            not null,
    height              number (8 ),
    upttime             date                 default sysdate not null,
    keyid               number (15 )           not null,
   constraint PK_T_ZHOBOTCODE primary key ( obtid ),
   constraint ZHOBTCODE_KEYID unique ( keyid )
);

comment on table T_ZHOBOTCODE is
'这是一个参数表，存放全国站点参数，约800条记录，本表的数据极少变更
应用程序对本表有insert和update操作';

comment on column T_ZHOBOTCODE. obtid  is
'站点代码';

comment on column T_ZHOBOTCODE. ciytname  is
'城市名称';

comment on column T_ZHOBOTCODE. provname  is
'省名称';

comment on column T_ZHOBOTCODE. lat  is
'纬度，单位：0.01度';

comment on column T_ZHOBOTCODE. lon  is
'经度，单位：0.01度';

comment on column T_ZHOBOTCODE. height  is
'海拔高度，单位：0.1米';

comment on column T_ZHOBOTCODE. upttime  is
'更新时间，数据被插入或更新的时间';

comment on column T_ZHOBOTCODE. keyid  is
'记录编号，自动增长列';

drop table T_ZHOBTMIND cascade constraints;

/*==============================================================*/
/* Table: T_ZHOBTMIND                                           */
/*==============================================================*/
drop    sequence SEQ_ZHOBTMIMD;
create  sequence SEQ_ZHOBTMIND increment by 1 minvalue 1 nocycle;
create table T_ZHOBTMIND 
(
    obtid               varchar2 (10 )         not null,
    ddatetime           date                 default sysdate not null,
    t                   number (8 ),
    p                   number (8 ),
    u                   number (8 ),
    wd                  number (8 ),
    wf                  number (8 ),
    r                   number (8 ),
    vis                 number (8 ),
    upttime             date                 default sysdate not null,
    keyid               number (15 )           not null,
   constraint PK_ZHOBTMIND primary key ( obtid ,  ddatetime ),
   constraint ZHOBTMIND_KEYID unique ( keyid )
);

comment on table T_ZHOBTMIND is
'本表存放了全国站点分钟数据，站点数约840个，数据周期为1分钟。
应用程序对本表只有insert操作，没有update和delete操作。';

comment on column T_ZHOBTMIND. obtid  is
'站点代码。';

comment on column T_ZHOBTMIND. ddatetime  is
'数据时间，精确到分钟。';

comment on column T_ZHOBTMIND. t  is
'湿度，单位：0.1摄氏度。';

comment on column T_ZHOBTMIND. p  is
'气压，单位：0.1百帕。';

comment on column T_ZHOBTMIND. u  is
'相对湿度，0-100之间的值。';

comment on column T_ZHOBTMIND. wd  is
'风向，0-360之间的值。';

comment on column T_ZHOBTMIND. wf  is
'风速：单位0.1m/s。';

comment on column T_ZHOBTMIND. r  is
'降雨量：0.1mm。';

comment on column T_ZHOBTMIND. vis  is
'能见度：0.1米。';

comment on column T_ZHOBTMIND. upttime  is
'更新时间。';

comment on column T_ZHOBTMIND. keyid  is
'记录编号，自动增长列。';

/*==============================================================*/
/* Index: IDX_ZHOBTMIND_1                                       */
/*==============================================================*/
create unique index IDX_ZHOBTMIND_1 on T_ZHOBTMIND (
    obtid  ASC,
    ddatetime  ASC
);

/*==============================================================*/
/* Index: IDX_ZHOBTMIND_2                                       */
/*==============================================================*/
create index IDX_ZHOBTMIND_2 on T_ZHOBTMIND (
    ddatetime  ASC
);

/*==============================================================*/
/* Index: IDX_ZHOBTMIND_3                                       */
/*==============================================================*/
create index IDX_ZHOBTMIND_3 on T_ZHOBTMIND (
    obtid  ASC
);

drop table T_ZHOBTCODE1 cascade constraints;

/*==============================================================*/
/* Table: T_ZHOBTCODE1                                          */
/*==============================================================*/
drop    sequence SEQ_ZHOBTCODE1;
create  sequence SEQ_ZHOBTCODE1 increment by 1 minvalue 1 nocycle;
create table T_ZHOBTCODE1 
(
    obtid               varchar2 (10 )         not null,
    cityname            varchar2(30)         not null,
    provname            varchar2 (10 )         not null,
    lat                 number (8 )            not null,
    lon                 number (8 )            not null,
    height              number (8 ),
    upttime             date                 default sysdate not null,
    keyid               number (8 )            not null,
   constraint PK_T_ZHOBTCODE1 primary key ( obtid ),
   constraint ZHOBTCODE1_KEYID unique ( keyid )
);

comment on table T_ZHOBTCODE1 is
'测试用';

comment on column T_ZHOBTCODE1. obtid  is
'站点代码';

comment on column T_ZHOBTCODE1. cityname  is
'城市名称';

comment on column T_ZHOBTCODE1. provname  is
'省名称';

comment on column T_ZHOBTCODE1. lat  is
'纬度，单位：0.01度';

comment on column T_ZHOBTCODE1. lon  is
'经度，单位：0.01度';

comment on column T_ZHOBTCODE1. height  is
'海拔高度，单位：0.1米';

comment on column T_ZHOBTCODE1. upttime  is
'更新时间，数据被插入或更新的时间';

comment on column T_ZHOBTCODE1. keyid  is
'记录编号，自动增长列';

drop table T_ZHOBTMIND1 cascade constraints;

/*==============================================================*/
/* Table: T_ZHOBTMIND1                                          */
/*==============================================================*/
drop    sequence SEQ_ZHOBTMIMD1;
create  sequence SEQ_ZHOBTMIND1 increment by 1 minvalue 1 nocycle;
create table T_ZHOBTMIND1 
(
    obtid               varchar2 (10 )         not null,
    ddatetime           date                 default sysdate not null,
    t                   number (8 ),
    p                   number (8 ),
    u                   number (8 ),
    wd                  number (8 ),
    wf                  number (8 ),
    r                   number (8 ),
    vis                 number (8 ),
    upttime             date                 default sysdate not null,
    keyid               number (15 )           not null,
   constraint PK_ZHOBTMIND1 primary key ( obtid ,  ddatetime ),
   constraint ZHOBTMIND1_KEYID unique ( keyid )
);

comment on table T_ZHOBTMIND1 is
'测试用';

comment on column T_ZHOBTMIND1. obtid  is
'站点代码。';

comment on column T_ZHOBTMIND1. ddatetime  is
'数据时间，精确到分钟。';

comment on column T_ZHOBTMIND1. t  is
'湿度，单位：0.1摄氏度。';

comment on column T_ZHOBTMIND1. p  is
'气压，单位：0.1百帕。';

comment on column T_ZHOBTMIND1. u  is
'相对湿度，0-100之间的值。';

comment on column T_ZHOBTMIND1. wd  is
'风向，0-360之间的值。';

comment on column T_ZHOBTMIND1. wf  is
'风速：单位0.1m/s。';

comment on column T_ZHOBTMIND1. r  is
'降雨量：0.1mm。';

comment on column T_ZHOBTMIND1. vis  is
'能见度：0.1米。';

comment on column T_ZHOBTMIND1. upttime  is
'更新时间。';

comment on column T_ZHOBTMIND1. keyid  is
'记录编号，自动增长列。';

/*==============================================================*/
/* Index: IDX_ZHOBTMIND1_1                                       */
/*==============================================================*/
create unique index IDX_ZHOBTMIND1_1 on T_ZHOBTMIND1 (
    obtid  ASC,
    ddatetime  ASC
);

/*==============================================================*/
/* Index: IDX_ZHOBTMIND1_2                                       */
/*==============================================================*/
create index IDX_ZHOBTMIND1_2 on T_ZHOBTMIND1 (
    ddatetime  ASC
);

/*==============================================================*/
/* Index: IDX_ZHOBTMIND1_3                                       */
/*==============================================================*/
create index IDX_ZHOBTMIND1_3 on T_ZHOBTMIND1 (
    obtid  ASC
);

/*==============================================================*/
/* Index: IDX_ZHOBTMIND1_4                                       */
/*==============================================================*/
create index IDX_ZHOBTMIND1_4 on T_ZHOBTMIND1 (
    t  ASC
);


