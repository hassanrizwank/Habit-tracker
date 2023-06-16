#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int habits=1, max_tdays=0, best_habit=0;
	int key[5], unit[5], goal[5], tdays[5] = {-1, -1, -1, -1, -1}, copy_tdays[5] = {0}, streak[5] = {0}, longeststreak[5] = {0};
	float sum[5] = {0}, percentage[5], greatest_percentage = 0, change = 0, track[5][100] = {{0}, {0}};

	puts("Welcome to HR HABIT TRACKER!");
	puts("How many habits would you like to adopt?");
	scanf("%d", &habits);

	for(int i=0; i<=(habits-1); i++)
    {

    puts("Choose a habit from below:");
	puts("1. Reading\n2. Working Out\n3. Calorie-consumption\n4. Sleeping\n5. Drinking Water");
	scanf("%d", &key[i]);
	puts("Select the appropriate unit:");
	puts("1. Joules\n2. Minutes/Hours\n3. Iterations");
	scanf("%d", &unit[i]);
	if(unit[i] == 2)
    {
        puts("4. Minutes\n5. Hours");
        scanf("%d", &unit[i]);
    }
	printf("Set a goal (day): ");
	scanf("%d", &goal[i]);
	printf("Enter the number of days you would like to track your progess.");
	scanf("%d", &tdays[i]);

    }

	puts("\nSTART TRACKING\n(Enter the magnitude of the unit you achieved)");

	for(int i=0; i<=(habits-1); i++)
    {
        if(tdays[i]>max_tdays)
        {
            max_tdays = tdays[i];
        }
    }

    for(int i=0; i<=(habits-1); i++)
    {
        copy_tdays[i] = tdays[i];
    }

    //MAX 5 HABITS CAN BE TAKEN
    for(int i=1; max_tdays>=1; max_tdays--, i++)
    {
        printf("\nDay %d: \n", i);

        for(int j=0; j<=(habits-1); j++)
        {
            switch(key[j])
            {
            case 1: printf("Reading");
            break;
            case 2: printf("Working out");
            break;
            case 3: printf("Calorie-consumption");
            break;
            case 4: printf("Sleeping");
            break;
            case 5: printf("Drinking Water");
            break;
            }
            switch(unit[j])
            {
                case 1: printf(" (Joules): ");
                break;
                case 3: printf(" (Iterations): ");
                break;
                case 4: printf(" (Minutes): ");
                break;
                case 5: printf(" (Hours): ");
                break;
            }
            if(tdays[j]>=1)
            {
                scanf("%f", &track[j][i-1]);
                tdays[j]--;
            }
            else
            {
            puts("Habit Completed");
            }
        }
    }

    //SUMMING THE PROGRESS
    for(int i=0; i<=(habits-1); i++)
    {
        for(int a=0; a<=(copy_tdays[i]-1); a++)
        {
            sum[i] += track[i][a];
        }
    }

    //PRESENTING STATS
    puts("\nStats about your progress:");

    //TOTAL QUANTITY
    puts("\nTotal quantity achieved of the habits: ");
    for(int i=0; i<=(habits); i++)
    {
        switch(key[i])
            {
            case 1: printf("Reading: %.2f ", sum[i]);
            break;
            case 2: printf("Working out: %.2f ", sum[i]);
            break;
            case 3: printf("Calorie-consumption: %.2f ", sum[i]);
            break;
            case 4: printf("Sleeping: %.2f ", sum[i]);
            break;
            case 5: printf("Drinking Water: %.2f ", sum[i]);
            break;
            }
            switch(unit[i])
            {
                case 1: puts(" joules");
                break;
                case 3: puts(" iterations");
                break;
                case 4: puts(" minutes");
                break;
                case 5: puts(" hours");
                break;
            }
        }

    //AVERAGE UNIT PER DAY
    puts("\nAverage Unit achieved(per day): ");
    for(int i=0; i<=habits; i++)
    {
        if(sum[i]!=0)
        {
            switch(key[i])
            {
            case 1: printf("Reading: %.2f ", (sum[i]/copy_tdays[i]));
            break;
            case 2: printf("Working out: %.2f ", (sum[i]/copy_tdays[i]));
            break;
            case 3: printf("Calorie-consumption: %.2f ", (sum[i]/copy_tdays[i]));
            break;
            case 4: printf("Sleeping: %.2f ", (sum[i]/copy_tdays[i]));
            break;
            case 5: printf("Drinking Water: %.2f ", (sum[i]/copy_tdays[i]));
            break;
            }
            switch(unit[i])
            {
                case 1: puts(" joules");
                break;
                case 3: puts(" iterations");
                break;
                case 4: puts(" minutes");
                break;
                case 5: puts(" hours");
                break;
            }
        }
    }

    //LONGEST STREAK
    puts("\nLongest Streak: ");
    for(int i=0; i<=(habits-1); i++)
    {
        for(int b=0; b<=(copy_tdays[i]-1); b++)
        {
            if(track[i][b]>=goal[i])
            {
                streak[i] = 0;
                while(track[i][b]>=goal[i])
                {
                    streak[i]++;
                    b++;
                }
            }
            if(streak[i]>longeststreak[i])
            {
                longeststreak[i] = streak[i];
            }
        }
        if(longeststreak[i]!=0)
        {
                switch(key[i])
            {
            case 1: printf("Reading: %d days\n", longeststreak[i]);
            break;
            case 2: printf("Working out: %d days\n", longeststreak[i]);
            break;
            case 3: printf("Calorie-consumption: %d days\n", longeststreak[i]);
            break;
            case 4: printf("Sleeping: %d days\n", longeststreak[i]);
            break;
            case 5: printf("Drinking Water: %d days\n", longeststreak[i]);
            break;
            }
        }
    }

    //HABIT BEST ADOPTED, (greatest %age of goal achieved)
    puts("\nHabit Best adopted: ");
    for(int i=0; i<=(habits-1); i++)
    {
        percentage[i] = sum[i]/(copy_tdays[i]*goal[i]) * 100;
        if(percentage[i]>greatest_percentage)
        {
            greatest_percentage = percentage[i];
            best_habit = (i+1);
        }
    }
    switch(key[best_habit])
            {
            case 1: printf("Reading. You achieved %.2f %% of your goal.\n", greatest_percentage);
            break;
            case 2: printf("Working out. You achieved %.2f %% of your goal.\n", greatest_percentage);
            break;
            case 3: printf("Calorie-consumption. You achieved %.2f %% of your goal.\n", greatest_percentage);
            break;
            case 4: printf("Sleeping. You achieved %.2f %% of your goal.\n", greatest_percentage);
            break;
            case 5: printf("Drinking Water. You achieved %.2f %% of your goal.\n", greatest_percentage);
            break;
            }

    printf("\nSubstitute for graph");
    for(int i=0; i<=(habits-1); i++)
    {
        switch(key[i])
        {
            case 1: puts("\nReading: ");
            break;
            case 2: puts("\nWorking Out: ");
            break;
            case 3: puts("\nCalorie-Consumption: ");
            break;
            case 4: puts("\nSleeping: ");
            break;
            case 5: puts("\nDrinking Water: ");
            break;
        }
        for(int a=1; a<=(copy_tdays[i]-1); a++)
        {
             change = ((track[i][a] - track[i][a-1]) / track[i][a-1]) * 100;
             printf("%.1f%% \n", change);
        }
    }

	return 0;

}





















































