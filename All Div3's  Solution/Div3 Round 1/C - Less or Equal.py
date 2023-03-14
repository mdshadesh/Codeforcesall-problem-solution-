def less_great():
    f,g = list(map(int,input().split()))

    nums = list(map(int,input().split()))

    nums.sort()

    nums = [1] + nums + [float('inf')]

    if nums[g+1] - nums[g] > 0:
        print(nums[g])

    else:
        print(-1)
less_great()

     				 	 	 	   	 		  			 	 	