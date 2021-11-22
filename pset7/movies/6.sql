SELECT AVG(ratings.rating) FROM ratings 
    JOIN movies ON ratings.movie_id = movies.id
    Where movies.year =2012;