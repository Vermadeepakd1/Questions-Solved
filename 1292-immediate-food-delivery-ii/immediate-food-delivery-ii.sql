# Write your MySQL query statement below
with rankedorders as
(
    select order_date, customer_pref_delivery_date ,
    row_number() over(
        partition by customer_id
        order by order_date asc
    ) as rnk
    from Delivery
)
select ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage
FROM RankedOrders
WHERE rnk = 1;