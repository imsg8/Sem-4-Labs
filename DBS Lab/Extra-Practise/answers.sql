1)
select cname from customer where address like '%Manipal%';


2)
select sum(qty*unitprice) as TotalAmount from sales where sales.cid = (select cid from customer where cname = 'Mohan');

3)
