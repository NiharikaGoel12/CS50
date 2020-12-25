select distinct title from movies where id in
(select distinct movie_id from
(select movie_id, count(person_id) as star_count from stars where person_id in
(select id from people where name = 'Johnny Depp' or name = 'Helena Bonham Carter')
group by movie_id
having star_count > 1));

/*
write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Johnny Depp.
You may assume that there is only one person in the database with the name Helena Bonham Carter.
*/