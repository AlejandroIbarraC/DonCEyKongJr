package com.donkeykongjr.logic;

public class Game {

    private Game(){
        gameMatrix = new Integer[24][16];
    }

    private static Game game = null;

    public static Game getInstance(){
        if (game == null){
            game = new Game();
        }
        return game;
    }


    Integer nothing = 0;
    Integer field = 1;
    Integer vyne = 2;
    Integer fruit = 3;
    Integer redEnemy = 4;
    Integer blueEnemy =5;
    Integer dCKong = 6;
    Integer [][] gameMatrix;



    protected void AddMatrix(){
        for(Integer i = 0; i < 15; i++){
            for(Integer j = 0; j < 15; j++){
                gameMatrix[i][j] = 0;
            }
        }
    }
    public void addFruitToMatrix(Integer i , Integer j){
        if(i != null && j != null)
            gameMatrix[i][j] = fruit;
    }
    public void addRedEnemyToMatrix(Integer i , Integer j){
        if(i != null && j != null)
            gameMatrix[i][j] = redEnemy;
    }
    public void addBlueEnemyToMatrix(Integer i , Integer j){
        if(i != null && j != null)
            gameMatrix[i][j] = blueEnemy;
    }
}
