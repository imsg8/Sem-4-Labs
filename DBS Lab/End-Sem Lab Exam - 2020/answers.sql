-- TABLE CREATION

-- Match(MatchID, TeamName1, TeamName2, Ground, MatchDate)
-- Player(PlayerID, LastName, FirstName, Country, YearBorn, BirthPlace)
-- Batting(MatchID, PlayerID, BattingOrder, RunsScored)

-- MatchID in Batting table refers to MatchID of Match Table
-- PlayerID in Batting table refers to PlayerID of Player Table

create table match(
    matchid number(10) primary key,
    teamname1 char(15),
    teamname2 char(15),
    ground char(15),
    matchdate date
);

create table player(
    playerid number(10) primary key,
    lastname char(15),
    firstname char(15),
    country char(15),
    yearborn number(10),
    birthplace char(15)
);

create table batting(
    matchid number(10),
    playerid number(10),
    runsscored number(10),
    battingorder number(10),
    foreign key (matchid) references match(matchid),
    foreign key (playerid) references player(playerid)
);

--INSERTION INTO TABLES 

insert into match values(2675, 'Australia', 'India', 'Melbourne', to_date('10-2-2008','DD-MM-YYYY'));
insert into match values(2688, 'Australia', 'India', 'Sydney', to_date('2-3-2008','DD-MM-YYYY'));
insert into match values(2689, 'Australia', 'India', 'Brisbane', to_date('4-3-2008','DD-MM-YYYY'));
insert into match values(2755, 'India', 'West Indies', 'Brisbane', to_date('7-7-2010','DD-MM-YYYY'));
insert into match values(2750, 'Sri Lanka', 'India', 'Brisbane', to_date('7-4-2010','DD-MM-YYYY'));


insert into player values(89001, 'Tendulkar', 'Sachin', 'India', 1973, 'Mumbai');
insert into player values(27002, 'Sharma', 'Ishant', 'India', 1988, 'Delhi');
insert into player values(99001, 'Lee', 'Brett', 'Australia', 1976, 'Wollongong');
insert into player values(98002, 'Lara', 'Brian', 'West Indies', 1969, 'Santa Cruz');
insert into player values(91001, 'Jayasurya', 'Sanath', 'Sri Lanka', 1969, 'Matara');


insert into batting values(2689, 89001, 71, 1);
insert into batting values(2688, 98002, 42, 2);
insert into batting values(2675, 27002, 0, 2);
insert into batting values(2689, 99001, 9, 2);
insert into batting values(2755, 89001, 44, 1);
insert into batting values(2750, 89001, 40, 4);
insert into batting values(2755, 27002, 29, 3);
insert into batting values(2675, 27002, 0, 4);



-- SQL QUERIES

-- Q) Find all the information about players from India who were born after 1975.
select * from player where country='India' and yearborn > 1975;

-- Q) List matches played in which TeamName1 is India or Australia.
select * from match where teamname1 in ('India', 'Australia');

-- Q) Find the names of all players that have batted in all the ODI matches in Melbourne ground.
select * from match a, player b, batting c where b.playerid = c.playerid and c.matchid = a.matchid and a.ground = 'Melbourne'
-- NEED TO CHECK THIS ONCE //

-- Q) Create a PLSQL block to read a player id and display his total number of runs in words.
-- (i.e. if the total runs is 10 then display “ONE” "ZERO”).
