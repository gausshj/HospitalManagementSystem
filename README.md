---
A management system of hospital database(Sql Server)


---

[toc]

# 一、题目需求说明

某医院需要建立信息管理系统，要求开发一套软件系统实现管理工作

（一）主要业务要求

（1） 该医院中的每个科室有多个病房、多个医生，一个病房只能属于一个科室，一个医生只属于一个科室，但可以负责多个病人的诊治，一个病人的主管医生只有一个。

（2） 要求建立用户界面（窗口或网页）对数据进行访问。实现医院信息的管理，能够根据条件查询科室、医生、病房及病人的相关信息（包括单表查询及较为复杂的多表查询），能对同一科室的医生进行分类统计，能修改、删除医生、病人等相关信息。

（二）主要数据要求

科室的属性有科室编号、科室名、科地址、联系电话、科室主任编号。医生的属性有工作证号、姓名、年龄、性别、职称、工资信息。病人的属性有病历号、姓名、性别、年龄、入院日期和出院日期。病房的属性有病房号和病房地址。

# 二、模型设计

题目所给数据类型如下：

- 科室的属性有科室编号、科室名、科地址、联系电话、科室主任编号。

- 医生的属性有工作证号、姓名、年龄、性别、职称、工资信息。

- 病人的属性有病历号、姓名、性别、年龄、入院日期和出院日期。

- 病房的属性有病房号和病房地址。

  在软件powerdesigner中建立概念模型，概念模型如下图所示。



 对数据建立概念模型后，我们需要将其转化为关系模型，通过powerdesigner     
 中关系转化功能，将概念模型转化为关系模型，关系模型如下图所示。



# 三、系统设计

各个部门在powerdesigner设计中对应的变量名称及类型如下表：

科室/Office

| 名称         | 简称  | 类型         | 键的类型 |
| ------------ | ----- | ------------ | -------- |
| 科室编号     | ono   | varchar(12)  | p        |
| 科室名       | oname | varchar(50)  |          |
| 科地址       | oadd  | varchar(100) |          |
| 联系电话     | otel  | varchar(12)  |          |
| 科室主任编号 | odno  | varchar(12)  |          |

病房/Ward

| 名称     | 简称 | 类型         | 键的类型 |
| -------- | ---- | ------------ | -------- |
| 病房号   | wno  | varchar(12)  | p        |
| 科室编号 | ono  | varchar(12)  | f        |
| 病房住址 | wadd | varchar(100) |          |

医生/Doctor

| 名称     | 简称    | 类型        | 键的类型 |
| -------- | ------- | ----------- | -------- |
| 工作编号 | dwcno   | varchar(12) | p        |
| 科室编号 | ono     | varchar(12) | f        |
| 医生姓名 | dname   | varchar(50) |          |
| 医生年龄 | dage    | int         |          |
| 医生性别 | dsex    | char(2)     |          |
| 职称     | dtitle  | varchar(50) |          |
| 工资信息 | dsalary | int         |          |

病人/Patient

| 名称     | 简称  | 类型        | 键的类型 |
| -------- | ----- | ----------- | -------- |
| 病历号   | pmrno | varchar(20) | p        |
| 科室编号 | ono   | varchar(12) | f        |
| 工作编号 | dwcno | varchar(12) | f        |
| 病人姓名 | pname | varchar(50) |          |
| 病人性别 | psex  | char(2)     |          |
| 病人年龄 | pag   | int         |          |
| 入院日期 | pdoa  | date        |          |
| 出院日期 | pdod  | date        |          |

在数据库中设计如下：

科室/Office

| 名称     | 科室编号 | 科室名   | 科地址   | 联系电话 | 科室主任编号 |
| -------- | -------- | -------- | -------- | -------- | ------------ |
| 简称     | ono      | oname    | oadd     | otel     | odno         |
| 类型     | char(8)  | char(10) | char(15) | char(12) | char(8)      |
| 键的类型 | 主键     |          |          |          |              |

医生/Doctor

| 名称     | 工作编号 | 姓名    | 年龄   | 性别    | 职称    | 工资信息 |
| -------- | -------- | ------- | ------ | ------- | ------- | -------- |
| 简称     | dwcno    | dname   | oadd   | dsex    | dtitle  | dsalary  |
| 类型     | char(8)  | char(5) | int(2) | char(2) | char(4) | int(8)   |
| 键的类型 | 主键     |         |        |         |         |          |

病人/Patient

| 名称     | 病历号   | 姓名    | 性别    | 年龄   | 入院日期 | 出院日期 |
| -------- | -------- | ------- | ------- | ------ | -------- | -------- |
| 简称     | pmrno    | pname   | psex    | page   | pdoa     | pdod     |
| 类型     | char(12) | char(5) | char(2) | int(2) | data     | data     |
| 键的类型 | 主键     |         |         |        |          |          |

病房/Ward

| 名称     | 病房号  | 病房住址 |
| -------- | ------- | -------- |
| 简称     | wno     | wadd     |
| 类型     | char(6) | char(10) |
| 键的类型 | 主键    |          |

# 四、SqlServer新建查询

新建查询，输入一下语句

```sql
create table Office(
	ono varchar(12) primary key,
	oname varchar(50),
	oadd varchar(100),
	otel varchar(12),
	odno varchar(12));
create table Ward(
	wno varchar(12) primary key,
	ono varchar(12) foreign key references Office(ono),
	wadd varchar(100));
create table Doctor(
	dwcno varchar(12) primary key,
	ono varchar(12) foreign key references Office(ono),
	dname varchar(50),
	dage int,
	dsex char(2),
	dtitle varchar(50),
	dsalary int);
create table Patient(
	pmrno varchar(20) primary key,
	ono varchar(12) foreign key references Office(ono),
	dwcno varchar(12) foreign key references Doctor(dwcno),
	pname varchar(50),
	psex char(2),
	pag int,
	pdoa date,
	pdod date);
```

# 五、系统说明

## 1、系统实现功能说明

目前本系统实现了对数据库的增删查，修改功能由于时间原因暂时没有完成，部分地方可能存在bug及未完善的地方。由于本人精力有限，目前没有时间完善。

## 2、系统存在问题及改进方向

- 查询数据时窗口大小和表的大小不匹配；
- 目前本系统尚不支持修改功能；

- 尚不支持图标功能；
- 部分窗口存在小问题；
- UI界面需要美化；
- 没有添加不同用户的管理系统。
