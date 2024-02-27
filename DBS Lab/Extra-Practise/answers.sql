1)
select cname from customer where address like '%Manipal%';


2)
select sum(qty*unitprice) as TotalAmount from sales where sales.cid = (select cid from customer where cname = 'Mohan');

3)
select sum(qty*unitprice) as total from sales where cid in(select cid from customer where cname='Mohan');
select cname from customer where cid in(select cid from sales group by cid having count(distinct(item))=(select count(distinct item) from sales));
--Thanks Shagnik Guha for answer to Query 3 :)
