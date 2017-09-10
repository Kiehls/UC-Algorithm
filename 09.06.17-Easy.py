class Solution(object):
    def maxProfit(self, prices):
        if not prices:
            return 0
        buy_price = prices[0]

        profit = 0
        for sell_price in prices:
            if buy_price > sell_price:
                buy_price = sell_price
                continue

            if profit < sell_price - buy_price:
                profit = sell_price - buy_price

        return profit
