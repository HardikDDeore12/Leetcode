SELECT 
    s.user_id, 
    ROUND( IFNULL(n.confirmed / (n.confirmed + n.timeout), 0),2) AS confirmation_rate
FROM Signups s
LEFT JOIN (
    SELECT 
        user_id,
        SUM(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END) AS confirmed,
        SUM(CASE WHEN action = 'timeout' THEN 1 ELSE 0 END) AS timeout
    FROM Confirmations 
    GROUP BY user_id
) n ON s.user_id = n.user_id;
