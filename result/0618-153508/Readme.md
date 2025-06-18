# Daily Evaluation 18/06 - 15:35:08
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 22/23 :  95%
## Detail by Feature
| Feature     | Score       | Missed tests                     | Stdout                  |
| :---------- | :---------- | :------------------------------- | :---------------------- |
| dimension   | 4/4 :  100% |                                  |                         |
| first_pixel | 5/5 :  100% |                                  |                         |
| tenth_pixel | 5/5 :  100% |                                  |                         |
| second_line | 4/5 :  80%  | Second line First Pixel 21 22 23 | second_line: 32, 32, 32 |
| print_pixel | 4/4 :  100% |                                  |                         |

# Milestone  statistiques
Score : 17/26 :  65%
## Detail by Feature
| Feature         | Score       | Missed tests                                                                        | Stdout   |
| :-------------- | :---------- | :---------------------------------------------------------------------------------- | :------- |
| max_pixel       | 4/4 :  100% |                                                                                     |          |
| min_pixel       | 4/4 :  100% |                                                                                     |          |
| min_component R | 0/3 :  0%   | Min Component R of black 8x8<br>Min Component R of white 8x8<br>Min Component 2 0 5 | <br><br> |
| min_component G | 0/3 :  0%   | Min Component G of black 8x8<br>Min Component G of white 8x8<br>Min Component 2 0 5 | <br><br> |
| min_component B | 0/3 :  0%   | Min Component B of black 8x8<br>Min Component B of white 8x8<br>Min Component 2 0 5 | <br><br> |
| max_component R | 3/3 :  100% |                                                                                     |          |
| max_component G | 3/3 :  100% |                                                                                     |          |
| max_component B | 3/3 :  100% |                                                                                     |          |

# Milestone  colors
Score : 30/35 :  85%
## Detail by Feature
| Feature              | Score       | Missed tests                                                                                                                                         | Stdout           |
| :------------------- | :---------- | :--------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------- |
| color_red            | 5/5 :  100% |                                                                                                                                                      |                  |
| color_blue           | 5/5 :  100% |                                                                                                                                                      |                  |
| color_green          | 5/5 :  100% |                                                                                                                                                      |                  |
| color_gray           | 5/5 :  100% |                                                                                                                                                      |                  |
| color_invert         | 5/5 :  100% |                                                                                                                                                      |                  |
| color_gray_luminance | 5/5 :  100% |                                                                                                                                                      |                  |
| color_desaturate     | 0/5 :  0%   | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY | <br><br><br><br> |

# Milestone  transform
Score : 12/15 :  80%
## Detail by Feature
| Feature           | Score       | Missed tests                                                   | Stdout   |
| :---------------- | :---------- | :------------------------------------------------------------- | :------- |
| rotate_cw         | 3/3 :  100% |                                                                |          |
| rotate_acw        | 3/3 :  100% |                                                                |          |
| mirror_horizontal | 3/3 :  100% |                                                                |          |
| mirror_vertical   | 3/3 :  100% |                                                                |          |
| mirror_total      | 0/3 :  0%   | mirror square image<br>mirror large image<br>mirror high image | <br><br> |

# Milestone  resize
Score : 0/60 :  0%
## Detail by Feature
| Feature        | Score      | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :--------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 0/20 :  0% | scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3                                                                                 | <br><br><br><br><br><br><br><br>… |
| scale_bilinear | 0/20 :  0% | scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12                               | <br><br><br><br><br><br><br><br>… |
| scale_crop     | 0/20 :  0% | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | <br><br><br><br><br><br><br><br>… |

