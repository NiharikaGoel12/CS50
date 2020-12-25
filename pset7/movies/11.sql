SELECT movies.title as movie_title from people
join stars on people.id = stars.person_id
join ratings on ratings.movie_id = stars.movie_id
join movies on movies.id = ratings.movie_id
where people.name = 'Chadwick Boseman'
order by ratings.rating DESC
LIMIT 5;

-- write a SQL query to list the titles of the five highest rated movies (in order)
--that Chadwick Boseman starred in, starting with the highest rated.
