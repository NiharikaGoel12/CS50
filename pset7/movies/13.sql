select distinct name from people where id in (
select person_id from stars where movie_id in
(select movie_id from stars where person_id in
(select id from people where name = 'Kevin Bacon' and birth = 1958))
) and name != 'Kevin Bacon';

/*
write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
Your query should output a table with a single column for the name of each person.
There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
Kevin Bacon himself should not be included in the resulting list.
*/

--Another long code:
-- select distinct name from people where id in(
-- select person_id from stars where movie_id in(
-- select movie_id from (
-- select movie_id, count(person_id) as star_count from stars where movie_id in
-- (select movie_id from stars where person_id in
-- (select id from people where name = 'Kevin Bacon' and birth = 1958))
-- group by movie_id
-- having star_count > 1))) and name != 'Kevin Bacon';