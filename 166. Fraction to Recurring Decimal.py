class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # 无小数部分
        if numerator % denominator == 0:
            return str(numerator // denominator)
        result = ""
        # 符号
        if (numerator < 0) != (denominator < 0):
            result += '-'
        # 整数部分
        numerator, denominator = abs(numerator), abs(denominator)
        result += str(numerator // denominator)
        # 小数点
        result += '.'
        # 小数部分
        remainder = numerator % denominator
        remainderMap = dict()
        while remainder:
            if remainder in remainderMap:  # 找到循环节
                result = result[:remainderMap[remainder]] + '(' + result[remainderMap[remainder]:]
                result += ')'
                break
            remainderMap[remainder] = len(result)  # 记住每个数字对应的位置
            remainder *= 10
            result += str(remainder // denominator)
            remainder %= denominator
        return result
