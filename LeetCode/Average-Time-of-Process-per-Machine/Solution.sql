1# Write your MySQL query statement below
2SELECT 
3    a.machine_id,
4    Round(AVG(b.timestamp - a. timestamp),3) as processing_time
5FROM Activity a
6JOIN Activity b
7    ON a.machine_id = b.machine_id
8    AND a.process_id = b.process_id
9    AND a.activity_type = 'start'
10    AND b.activity_type = 'end'
11GROUP BY a.machine_id;
12    