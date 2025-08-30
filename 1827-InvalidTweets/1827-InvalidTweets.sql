-- Last updated: 8/30/2025, 1:25:03 PM
SELECT tweet_id 
FROM Tweets 
WHERE CHAR_LENGTH(content) > 15;
