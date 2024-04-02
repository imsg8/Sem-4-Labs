-- TABLE CREATION

-- Match(MatchID, TeamName1, TeamName2, Ground, MatchDate)
-- Player(PlayerID, LastName, FirstName, Country, YearBorn, BirthPlace)
-- Batting(MatchID, PlayerID, BattingOrder, RunsScored)

-- MatchID in Batting table refers to MatchID of Match Table
-- PlayerID in Batting table refers to PlayerID of Player Table

create table match(
    matchid number(10) primary key,
    teamname1 char(10),
    teamname2 char(10),
    ground char(10),
    matchdate date
);

create table player(
    playerid number(10) primary key,
    lastname char(10),
    firstname char(10),
    country char(10),
    yearborn number(10),
    birthplace char(10)
);

create table batting(
    matchid number(10),
    playerid number(10),
    battingorder number(10),
    runsscored number(10),
    foreign key (matchid) references match(matchid),
    foreign key (playerid) references player(playerid)
);
