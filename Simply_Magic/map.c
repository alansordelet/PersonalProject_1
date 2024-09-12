#include"tools.h"
#include"map.h"
#include"Lighting.h"
sfSprite* groundSprite;
sfTexture* groundTexture;

sfSprite* InsideSprite;
sfTexture* InsideTexture;

sfSprite* HitBoxSprite;
sfTexture* HitBoxTexture;

sfVector2f viewEditorPosition;

float KeyTimer;
int click;
int clickOut;

sfIntRect HitBoxRect = { 0,0,16,16 };
long int clickHitBox;


sfIntRect solRect = { 0, 0, 16, 16};
sfIntRect ExtRect = { 0, 0, 16, 16};



void initMap()
{

    groundTexture = sfTexture_createFromFile(TEXTURE_PATH"ground.png", NULL);
    groundSprite = sfSprite_create();
    sfSprite_setTexture(groundSprite, groundTexture, sfTrue);
    loadmap();
}

void initMapInside()
{

    InsideTexture = sfTexture_createFromFile(TEXTURE_PATH"Tileset_Large.png", NULL);
    InsideSprite = sfSprite_create();
    sfSprite_setTexture(InsideSprite, InsideTexture, sfTrue);
    LoadMapIn();
}

void initMapHitBox()
{

    HitBoxTexture = sfTexture_createFromFile(TEXTURE_PATH"hitbox.png", NULL);
    HitBoxSprite = sfSprite_create();
    sfSprite_setTexture(HitBoxSprite, HitBoxTexture, sfTrue);
    loadMapHitBox();

    for (int y = 0; y < 75; y++)
    {

        for (int x = 0; x < 75; x++)
        {




        }
    }
}

void updateview(sfRenderWindow* _window)
{

    sfVector2i position;

    sfVector2i mousepositio;
    KeyTimer += GetDeltaTime();
    if (state == EDITOR)
    {

        if (sfKeyboard_isKeyPressed(sfKeySpace) && KeyTimer > 0.2)
        {
            state = GAME;
            KeyTimer = 0;
            sfView_reset(viewGame, FlRect(50.0f, 1000.0f, 200.0f, 210.0f));
            sfView_setCenter(viewGame, vector2f(300, 400));
            sfView_setViewport(viewGame, FlRect(0.0, 0.0, 1.0, 1.0));
       
            
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && KeyTimer > 0.2)
        {
            sfWindow_close(window);
            KeyTimer = 0;
          

        }
        if (stateEdit == COUCHESOL)
        {

            if (sfMouse_isButtonPressed(sfMouseRight))
            {
                mousepositio = sfMouse_getPosition(window);
                sfVector2f mapPixelToCoords;
                mapPixelToCoords = sfRenderWindow_mapPixelToCoords(window, mousepositio, viewEditor);
                position.x = (int)mapPixelToCoords.x / 16;
                position.y = (int)mapPixelToCoords.y / 16;
                click = map[position.y][position.x];
                printf("%d\n", click);
            }

            if (sfMouse_isButtonPressed(sfMouseLeft))
            {
                mousepositio = sfMouse_getPosition(window);
                sfVector2f mapPixelToCoords;
                mapPixelToCoords = sfRenderWindow_mapPixelToCoords(window, mousepositio, viewEditor);
                position.x = (int)mapPixelToCoords.x / 16;
                position.y = (int)mapPixelToCoords.y / 16;
                map[position.y][position.x] = click;

            }

            if (sfKeyboard_isKeyPressed(sfKeyL) && KeyTimer > 0.2)
            {
                if (click > 0)
                {
                    click -= 1;

                    printf("%d\n", click);
                }
                KeyTimer = 0.0f;
            }
            if (sfKeyboard_isKeyPressed(sfKeyM) && KeyTimer > 0.2)
            {
                if (click < 65)
                {
                    click += 1;

                    printf("%d\n", click);
                }
                KeyTimer = 0.0f;
            }
            if (sfKeyboard_isKeyPressed(sfKeyN) && KeyTimer > 0.2)
            {

                stateEdit = COUCHEDEHORS;

                KeyTimer = 0.0f;
            }
        }
        if (stateEdit == COUCHEDEHORS)
        {

            if (sfMouse_isButtonPressed(sfMouseRight))
            {
                mousepositio = sfMouse_getPosition(window);
                sfVector2f mapPixelToCoords;
                mapPixelToCoords = sfRenderWindow_mapPixelToCoords(window, mousepositio, viewEditor);
                position.x = (int)mapPixelToCoords.x / 16;
                position.y = (int)mapPixelToCoords.y / 16;
                clickOut = mapext[position.y][position.x];
                printf("%d\n", clickOut);
            }

            if (sfMouse_isButtonPressed(sfMouseLeft))
            {
                mousepositio = sfMouse_getPosition(window);
                sfVector2f mapPixelToCoords;
                mapPixelToCoords = sfRenderWindow_mapPixelToCoords(window, mousepositio, viewEditor);
                position.x = (int)mapPixelToCoords.x / 16;
                position.y = (int)mapPixelToCoords.y / 16;
                mapext[position.y][position.x] = clickOut;

            }

            if (sfKeyboard_isKeyPressed(sfKeyL) && KeyTimer > 0.2)
            {
                if (clickOut > 0)
                {
                    clickOut -= 1;

                    printf("%d\n", clickOut);
                }
                KeyTimer = 0.0f;
            }
            if (sfKeyboard_isKeyPressed(sfKeyM) && KeyTimer > 0.2)
            {
                if (clickOut < 256)
                {
                    clickOut += 1;

                    printf("%d\n", clickOut);
                }
                KeyTimer = 0.0f;
            }
            if (sfKeyboard_isKeyPressed(sfKeyN) && KeyTimer > 0.2)
            {

                stateEdit = HITBOX;

                KeyTimer = 0.0f;
            }

        }
        if (stateEdit == HITBOX)
        {

            if (sfMouse_isButtonPressed(sfMouseRight))
            {
                mousepositio = sfMouse_getPosition(window);
                sfVector2f mapPixelToCoords;
                mapPixelToCoords = sfRenderWindow_mapPixelToCoords(window, mousepositio, viewEditor);
                position.x = (int)mapPixelToCoords.x / 16;
                position.y = (int)mapPixelToCoords.y / 16;
                clickHitBox = maphitbox[position.y][position.x];
                printf("%d\n", clickHitBox);
            }

            if (sfMouse_isButtonPressed(sfMouseLeft))
            {
                mousepositio = sfMouse_getPosition(window);
                sfVector2f mapPixelToCoords;
                mapPixelToCoords = sfRenderWindow_mapPixelToCoords(window, mousepositio, viewEditor);
                position.x = (int)mapPixelToCoords.x / 16;
                position.y = (int)mapPixelToCoords.y / 16;
                maphitbox[position.y][position.x] = clickHitBox;

            }

            if (sfKeyboard_isKeyPressed(sfKeyL) && KeyTimer > 0.2)
            {
                if (clickHitBox > 0)
                {
                    clickHitBox -= 1;

                    printf("%d\n", clickHitBox);
                }
                KeyTimer = 0.0f;
            }
            if (sfKeyboard_isKeyPressed(sfKeyM) && KeyTimer > 0.2)
            {
                if (clickHitBox < 3)
                {
                    clickHitBox += 1;

                    printf("%d\n", clickHitBox);
                }
                KeyTimer = 0.0f;
            }
            if (sfKeyboard_isKeyPressed(sfKeyN) && KeyTimer > 0.2)
            {

                stateEdit = COUCHESOL;

                KeyTimer = 0.0f;
            }
        }

        if (sfKeyboard_isKeyPressed(sfKeyW))
        {
            viewEditorPosition.y -= 500.0f * GetDeltaTime();
        }
        if (sfKeyboard_isKeyPressed(sfKeyS))
        {
            viewEditorPosition.y += 500.0f * GetDeltaTime();
        }

        if (sfKeyboard_isKeyPressed(sfKeyA))
        {
            viewEditorPosition.x -= 500.0f * GetDeltaTime();
        }
        if (sfKeyboard_isKeyPressed(sfKeyD))
        {
            viewEditorPosition.x += 500.0f * GetDeltaTime();
        }
        sfView_setCenter(viewEditor, viewEditorPosition);
    }


}

void eventMap(sfEvent event, sfRenderWindow* _window)
{

    float viewZoom = 1;


    if (state == EDITOR)
    {
        if (event.type == sfEvtMouseWheelMoved)
        {
            if (event.mouseWheelScroll.wheel > 0)
            {
                viewZoom -= 0.1;
            }
            if (event.mouseWheelScroll.wheel < 0)
            {
                viewZoom += 0.1;
            }
            sfView_zoom(viewEditor, viewZoom);
        }
    }
       
    
}

void displayMap(sfRenderWindow* _window)
{

    for (int y = 0; y < 75; y++)
    {
        for (int x = 0; x < 75; x++)
        {
            // Affichage de la map pour le sol
            solRect.left = map[y][x] % 16 * 16;
            solRect.top = map[y][x] / 16 * 16;
            sfSprite_setTextureRect(groundSprite, solRect);
            sfSprite_setPosition(groundSprite, vector2f(x * solRect.width, y * solRect.height));
            sfRenderWindow_drawSprite(_window, groundSprite, &renderState);


        }

    }

    if (state == EDITOR)
    {
        
        if (stateEdit == COUCHESOL)
        {

            sfVector2i position;
            sfVector2i mousepositio;
            solRect.left = click % 16 * 16;
            solRect.top = click / 16 * 16;
            mousepositio = sfMouse_getPosition(_window);
            sfVector2f mapPixelToCoords;
            mapPixelToCoords = sfRenderWindow_mapPixelToCoords(_window, mousepositio, viewEditor);
            position.x = (int)mapPixelToCoords.x / 16;
            position.y = (int)mapPixelToCoords.y / 16;
            sfSprite_setTextureRect(groundSprite, solRect);
            sfSprite_setPosition(groundSprite, mapPixelToCoords);
            sfRenderWindow_drawSprite(_window, groundSprite, NULL);
        }
        
    }
}

void displayMapExt(sfRenderWindow* _window)
{
    
    for (int y = 0; y < 75; y++)
    {
        for (int x = 0; x < 75; x++)
        {



            // Affichage de la map pour le exterieur

            ExtRect.left = mapext[y][x] % 16 * 16;
            ExtRect.top = mapext[y][x] / 16 * 16;
            sfSprite_setTextureRect(InsideSprite, ExtRect);
            sfSprite_setPosition(InsideSprite, vector2f(x * ExtRect.width, y * ExtRect.height));
            sfRenderWindow_drawSprite(_window, InsideSprite, &renderState);


        }
    }
    if (state == EDITOR)
    {
        if (stateEdit == COUCHEDEHORS)
        {

            sfVector2i position;
            sfVector2i mousepositio;
            ExtRect.left = clickOut % 16 * 16;
            ExtRect.top = clickOut / 16 * 16;
            mousepositio = sfMouse_getPosition(_window);
            sfVector2f mapPixelToCoords;
            mapPixelToCoords = sfRenderWindow_mapPixelToCoords(_window, mousepositio, viewEditor);
            position.x = (int)mapPixelToCoords.x / 16;
            position.y = (int)mapPixelToCoords.y / 16;
            sfSprite_setTextureRect(InsideSprite, ExtRect);
            sfSprite_setPosition(InsideSprite, mapPixelToCoords);
            sfRenderWindow_drawSprite(_window, InsideSprite, NULL);
        }

    }

}

void loadmap()
{
    FILE* fichier;
    fichier = fopen("..\\Ressources\\Maps\\map10.map", "rt");
    int c = map;
    for (int y = 0; y < 75; y++)
    {
        for (int x = 0; x < 75; x++)
        {

            fscanf(fichier, "%d", &c);
            map[y][x] = c;


        }

    }
    fclose(fichier);
}

void LoadMapIn()
{
    FILE* fichier;
    fichier = fopen("..\\Ressources\\Maps\\mapext10.map", "rt");
    long int c = mapext;
    for (int y = 0; y < 75; y++)
    {
        for (int x = 0; x < 75; x++)
        {

            fscanf(fichier, "%d", &c);
            mapext[y][x] = c;


        }

    }
    fclose(fichier);
}

void loadMapHitBox()
{
    FILE* fichier;
    fichier = fopen("..\\Ressources\\Maps\\maphitbox10.map", "rt");
    int c = maphitbox;
    for (int y = 0; y < 75; y++)
    {
        for (int x = 0; x < 75; x++)
        {

            fscanf(fichier, "%d", &c);
            maphitbox[y][x] = c;


        }

    }
    fclose(fichier);
}

void displayMapHitBox(sfRenderWindow* _window)
{

    if (state == EDITOR)
    {
        if (stateEdit == HITBOX)
        {

            for (int y = 0; y < 75; y++)
            {
                for (int x = 0; x < 75; x++)
                {



                    // Affichage de la des hitbox

                    HitBoxRect.left = maphitbox[y][x] % 2 * 16;
                    HitBoxRect.top = maphitbox[y][x] / 2 * 16;
                    sfSprite_setTextureRect(HitBoxSprite, HitBoxRect);
                    sfSprite_setPosition(HitBoxSprite, vector2f(x * HitBoxRect.width, y * HitBoxRect.height));
                    sfRenderWindow_drawSprite(_window, HitBoxSprite, NULL);


                }
            }


            sfVector2i position;
            sfVector2i mousepositio;
            HitBoxRect.left = clickHitBox % 2 * 16;
            HitBoxRect.top = clickHitBox / 2 * 16;

            mousepositio = sfMouse_getPosition(_window);
            sfVector2f mapPixelToCoords;
            mapPixelToCoords = sfRenderWindow_mapPixelToCoords(_window, mousepositio, viewEditor);
            position.x = (int)mapPixelToCoords.x / 16;
            position.y = (int)mapPixelToCoords.y / 16;
            sfSprite_setTextureRect(HitBoxSprite, HitBoxRect);
            sfSprite_setPosition(HitBoxSprite, mapPixelToCoords);
            sfRenderWindow_drawSprite(_window, HitBoxSprite, NULL);
        }
    }

}



void savemap()
{
    FILE* fichier;
    fichier = fopen("..\\Ressources\\Maps\\map10.map", "w");
    for (int y = 0; y < 75; y++)
    {
        for (int x = 0; x < 75; x++)
        {

            fprintf(fichier, "%d", map[y][x]);
            fprintf(fichier, " ");

        }

    }

    fclose(fichier);
}



void savemapext()
{
    FILE* fichier;
    fichier = fopen("..\\Ressources\\Maps\\mapext10.map", "w");
    for (int y = 0; y < 75; y++)
    {
        for (int x = 0; x < 75; x++)
        {




            fprintf(fichier, "%d", mapext[y][x]);
            fprintf(fichier, " ");


            /*fprintf(fichier, "%d",8);
            fprintf(fichier, " ");*/

        }

    }

    fclose(fichier);
}


void saveMapHitBox()
{
    FILE* fichier;
    fichier = fopen("..\\Ressources\\Maps\\maphitbox10.map", "w");
    for (int y = 0; y < 75; y++)
    {
        for (int x = 0; x < 75; x++)
        {




            fprintf(fichier, "%d", maphitbox[y][x]);
            fprintf(fichier, " ");


            /*    fprintf(fichier, "%d",0);
                fprintf(fichier, " ");*/

        }

    }

    fclose(fichier);
}