set grammar to oracle;
select length('abcd!@#$^&*()') from dual;
select length('ab
c') from dual;
select length('你好') from dual;
select length('你
好') from dual;
select length(to_char(1234)) from dual;
select length(exp(2)) from dual;
select length(12.3456) from dual;
create table tt (name varchar2(10));
insert into tt values('1bd2sdfaef');
insert into tt values('3csadfed');
insert into tt values('mmsdeq4d');
insert into tt values('ccd');
select * from tt where length(name) >6 order by name;
select name,length(name) from tt order by name;
drop table tt;
